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
        qreal height;
        qreal width;
        qreal last_x;
        size_t size;
        QColor column_color;
        QGraphicsRectItem* create_column(T value);
    public:
        DiagramBuilder(qreal height, qreal width);
        //add line to diagram
        void append_column(T value);
    public:
        QGraphicsScene* get_scene();
    };
}
namespace sd
{
    template<typename T>
    DiagramBuilder<T>::DiagramBuilder(qreal height, qreal width):
        height{height}, width{width}, size{0},last_x{0}, scene{new QGraphicsScene()},column_color{QColor("black")}{}
    template<typename T>
    void DiagramBuilder<T>::append_column(T value)
    {
        scene->addItem(create_column(value));
    }
    template<typename T>
    QGraphicsRectItem* DiagramBuilder<T>::create_column(T value)
    {
        QGraphicsRectItem* rect = new QGraphicsRectItem();
        rect->setRect(last_x,150 - value,10,value);
        last_x+=10;
        return rect;
    }
    template<typename T>
    QGraphicsScene* DiagramBuilder<T>::get_scene()
    {
        return scene;
    }
}
#endif // DIAGRAM_BUILDER_H
