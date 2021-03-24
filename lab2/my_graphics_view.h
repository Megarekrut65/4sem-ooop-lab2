#ifndef MYGRAPHICSVIEW_H
#define MYGRAPHICSVIEW_H
#include "diagram_builder.h"
#include "Sorts/all_sorts.h"
namespace sd
{
    template<typename T>
    class MyGraphicsView
    {
    private:
        DiagramBuilder<T>* builder;
        const size_t width;
        const size_t height;
        QString title;
    public:
        MyGraphicsView(const QString& title, std::vector<T>& items, size_t width = 800,size_t height = 600);
        QGraphicsScene *get_scene();
        QGraphicsView* view;
        void show();
        void close();
        void create_new_scene(std::vector<T>& items);
        ~MyGraphicsView();
    };
}
namespace sd
{
    template<typename T>
    MyGraphicsView<T>::MyGraphicsView(const QString& title, std::vector<T>& items,size_t width,size_t height):
        title(title), view(nullptr),builder(nullptr), width(width), height(height)
    {
        create_new_scene(items);
    }


    template<typename T>
    MyGraphicsView<T>::~MyGraphicsView()
    {
        if(builder) delete builder;
        if(view) delete view;
        builder = nullptr;
        view = nullptr;
    }
    template<typename T>
    void MyGraphicsView<T>::create_new_scene(std::vector<T>& items)
    {
        if(builder) delete builder;
        builder = new sd::DiagramBuilder<T>(sorts::get_max(items), width, height, items.size());
        for(std::size_t i = 0; i < items.size(); i++)
            builder->append_column(items[i]);
        builder->add_description(title);
        QString des = "size: " + QString::number(items.size());
        builder->add_description(des);
    }
    template<typename T>
    void MyGraphicsView<T>::show()
    {
        view = new QGraphicsView(builder->get_scene());
        view->setBaseSize(800,600);
        view->setMinimumSize(800,600);
        view->setMaximumSize(800,600);
        view->setWindowTitle(title);
        view->show();
    }
    template<typename T>
    void MyGraphicsView<T>::close()
    {
        view->close();
    }

    template<typename T>
    QGraphicsScene *MyGraphicsView<T>::get_scene()
    {
        return builder->get_scene();
    }
}

#endif // MYGRAPHICSVIEW_H
