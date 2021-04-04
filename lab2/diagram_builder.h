#ifndef DIAGRAM_BUILDER_H
#define DIAGRAM_BUILDER_H
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsItem>
/*!
* \brief Sort diagram
*
* Namespace for the classes needed to create a chart from an array
*/
namespace sd
{
    /*!
    * \brief Template class to build a diagram
    *
    * Used a pattern - builder. See [Builder](https://en.wikipedia.org/wiki/Builder_pattern "Information about this pattern in Wikipedia")
    *
    * Adds to diagram some columns and sone textes. You can edit the color of columns.
    * Need to set maximum number of columns and maximun value of items to make correct diagram.
    *
    * Adds diagram to QGraphicsScene and you can take it using get_scene().
    */
    template<typename T>
    class DiagramBuilder
    {
    private:
        QGraphicsScene* scene;/*!< Scene for diagram */
        const qreal height;/*!< Height of diagram */
        const qreal width;/*!< Width of diagram */
        qreal last_x;/*!< X coordinate of last column */
        size_t size;/*!< Max number of columns */
        T max_item;/*!< Maximum value of all values in diagram */
        QColor column_color;/*!< Color of column */
        QString description;/*!< Text to add in diagram */
        const size_t text_size;/*!< Maximum size of description. If size will be big then can not add more text */
        /*!
        * \brief Creates column by value
        *
        * \param value - value of item
        * \returns column with height created by value
        */
        QGraphicsRectItem* create_column(T value);
        /*!
        * \brief Creates text item
        *
        * \param text - text of item
        * \param pos_x - x coordinate of item in diagram
        * \param pos_y - y coordinate of item in diagram
        * \param bold - if true then text will be bold
        * \returns text item with these parameters
        */
        QGraphicsTextItem* create_text(const QString& text, qreal pos_x, qreal pos_y,bool bold = false);
        /*!
        * \brief Adds the description to diagram
        */
        void set_description();
        /*!
        * \brief Adds empty column to diagram
        *
        * For symmetry
        */
        void add_empty_column();
    public:
        /*!
        * \brief Constructor to set importent parameters
        *
        * Need to set all parameters correctly.
        *
        * \param max_item - maximum value of item in diagram
        * \param width - width of diagram
        * \param height - height of diagram
        * \param size - maximum number of items in diagram
        */
        DiagramBuilder(T max_item, qreal width = 800, qreal height = 600, size_t size = 1);
        /*!
        *   \brief Adds column to end of diagram
        *
        *   \param value - value of item. Need to create height of column
        */
        void append_column(T value);
        /*!
        *   \brief Adds text to description
        *
        *   In the end the description will be added to diagram
        */
        void add_description(const QString& text);
        /*!
        *   \brief Adds all changes to diagram and returns scene with diagram
        *
        *   \returns scene with diagram
        */
        QGraphicsScene* get_scene();
        /*!
        *   \brief Clears scene and all parameters
        */
        void clear();
        /*!
        *   \brief Edits color of columns
        *
        *   \param column_color - new color of columns
        */
        void set_color(QColor column_color);
        /*!
        *   \brief Deletes all pointers in this class
        */
        ~DiagramBuilder();
    };
}
namespace sd
{
    template<typename T>
    DiagramBuilder<T>::DiagramBuilder(T max_item, qreal width,qreal height, size_t size):
         max_item{max_item}, width{width},height{height}, size{size > 50?size:50},last_x{0},
        scene{new QGraphicsScene()},column_color{QColor("blue")},text_size{20} {}
    template<typename T>
    void DiagramBuilder<T>::clear()
    {
        scene->clear();
        last_x = 0;
        description.clear();
        column_color = QColor("blue");
    }
    template<typename T>
    void DiagramBuilder<T>::set_color(QColor column_color)
    {
        this->column_color = column_color;
    }
    template<typename T>
    DiagramBuilder<T>::~DiagramBuilder()
    {
        if(scene) delete scene;
        scene = nullptr;
    }
    template<typename T>
    void DiagramBuilder<T>::append_column(T value)
    {
        scene->addItem(create_column(value));
    }
    template<typename T>
    QGraphicsTextItem* DiagramBuilder<T>::create_text(const QString& text, qreal pos_x, qreal pos_y,bool bold)
    {
        auto item = new QGraphicsTextItem();
        item->setPos(pos_x,pos_y);
        item->setPlainText(text);
        QFont font;
        font.setPixelSize(text_size);
        font.setBold(bold);
        font.setFamily("Arial");
        item->setFont(font);
        return item;
    }
    template<typename T>
    void DiagramBuilder<T>::add_description(const QString& text)
    {
        if(description.size()*text_size > width) return;
        description += text + "    ";
    }
    template<typename T>
    QGraphicsRectItem* DiagramBuilder<T>::create_column(T value)
    {
        qreal diagram_height = height - 100;
        qreal diagram_width = width - 20;
        auto rect = new QGraphicsRectItem();
        qreal item_height = max_item > 0?qreal((value * diagram_height)/max_item):diagram_height;
        qreal column_width = diagram_width/size;
        if(column_width < 1) column_width = 1;
        rect->setRect(last_x,diagram_height - 10 - item_height,column_width,item_height);
        rect->setBrush(column_color);
        last_x+=column_width;
        return rect;
    }
    template<typename T>
    void DiagramBuilder<T>::add_empty_column()
    {
        qreal diagram_width = width - 20;
        auto rect = new QGraphicsRectItem();
        rect->setRect(last_x,height - 110, diagram_width/size, 0);
        rect->setBrush(QColor("white"));
        last_x+=diagram_width/size;
    }
    template<typename T>
    void DiagramBuilder<T>::set_description()
    {
        if(description.size() == 0) return;
        qreal text_x = width/4 - description.size();
        scene->addItem(create_text(description, text_x, height - 80));
    }
    template<typename T>
    QGraphicsScene* DiagramBuilder<T>::get_scene()
    {
        set_description();
        if(size > 100) for(std::size_t i = 0; i < 5; i++) add_empty_column();
        return scene;
    }
}
#endif // DIAGRAM_BUILDER_H
