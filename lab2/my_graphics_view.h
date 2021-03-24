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
        QString note;
    public:
        MyGraphicsView(const QString& title,const QString& note, std::vector<T>& items, size_t width = 800,size_t height = 600);
        QGraphicsView* view;
        void show();
        void close();
        void create_new_scene(std::vector<T>& items, bool the_end = false);
        QGraphicsView* get_view();
        QGraphicsScene* get_scene();
        ~MyGraphicsView();
    };
}
namespace sd
{
    template<typename T>
    QGraphicsScene* MyGraphicsView<T>::get_scene()
    {
        return builder->get_scene();
    }
    template<typename T>
    QGraphicsView* MyGraphicsView<T>::get_view()
    {
        return view;
    }
    template<typename T>
    MyGraphicsView<T>::MyGraphicsView(const QString& title,const QString& note, std::vector<T>& items,size_t width,size_t height):
        title(title), note(note),view(new QGraphicsView()),builder(nullptr), width(width), height(height)
    {
        builder = new sd::DiagramBuilder<T>(sorts::get_max(items), width, height, items.size());
        create_new_scene(items);
        view->setBaseSize(width,height);
        view->setMinimumSize(width,height);
        view->setMaximumSize(width,height);
        view->setWindowTitle(title);
        view->setRenderHint(QPainter::Antialiasing);
        view->setViewportUpdateMode(QGraphicsView::BoundingRectViewportUpdate);

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
    void MyGraphicsView<T>::create_new_scene(std::vector<T>& items, bool the_end)
    {
        builder->clear();
        if(the_end) builder->set_color(QColor("green"));
        for(std::size_t i = 0; i < items.size(); i++)
            builder->append_column(items[i]);
        builder->add_description(title);
        QString des = "size: " + QString::number(items.size());
        builder->add_description(des);
        if(note.size() > 0) builder->add_description(note);
        view->setScene(builder->get_scene());
    }
    template<typename T>
    void MyGraphicsView<T>::show()
    {   
        view->show();
    }
    template<typename T>
    void MyGraphicsView<T>::close()
    {
        view->close();
    }
}

#endif // MYGRAPHICSVIEW_H
