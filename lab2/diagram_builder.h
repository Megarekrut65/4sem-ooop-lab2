#ifndef DIAGRAM_BUILDER_H
#define DIAGRAM_BUILDER_H
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsItem>
/*!
* Sort diagram
*/
namespace sd
{
    template<typename T>
    class DiagramBuilder
    {
    private:
        QGraphicsScene* scene;
        const qreal height;
        const qreal width;
        qreal last_x;
        size_t size;
        T max_item;
        QColor column_color;
        QString description;
        const size_t text_size;
        QGraphicsRectItem* create_column(T value);
        QGraphicsTextItem* create_text(const QString& text, qreal pos_x, qreal pos_y,bool bold = false);
        void set_description();
        void add_empty_column();
    public:
        DiagramBuilder(T max_item, qreal width = 800, qreal height = 600, size_t size = 1);
        void append_column(T value);
        void add_description(const QString& text);
        QGraphicsScene* get_scene();
        void clear();
        void set_color(QColor column_color);
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
        qreal item_height = qreal((value * diagram_height)/max_item);
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
        qreal text_x = width/2 - description.size() - 50;
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
