#ifndef MYGRAPHICSVIEW_H
#define MYGRAPHICSVIEW_H
#include "diagram_builder.h"
#include "Sorts/all_sorts.h"
#include "memento_sorting.h"
using namespace ms;
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
        QColor color;
        const QColor basic_color;
        const QColor end_color;
        const QColor pause_color;
        const QColor mark_color;
    public:
        MyGraphicsView(const QString& title,const QString& note, MementoSorting<T>* state, size_t width = 800,size_t height = 600);
        QGraphicsView* view;
        void show();
        void close();
        void create_new_scene(MementoSorting<T>* state,const QString& add_to_end = "", bool the_end = false);
        QGraphicsView* get_view();
        QGraphicsScene* get_scene();
        void set_pause_color();
        void set_start_color();
        void clear();
        ~MyGraphicsView();
    };
}
namespace sd
{
    template<typename T>
    void MyGraphicsView<T>::clear()
    {
        builder->clear();
        title = "";
        note = "";
        color = basic_color;
    }
    template<typename T>
    void MyGraphicsView<T>::set_pause_color()
    {
        color = pause_color;
    }
    template<typename T>
    void MyGraphicsView<T>::set_start_color()
    {
        color = basic_color;
    }
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
    MyGraphicsView<T>::MyGraphicsView(const QString& title,const QString& note, MementoSorting<T>* state,size_t width,size_t height):
        title(title), note(note),view(new QGraphicsView()),builder(nullptr), width(width), height(height),
        basic_color(QColor("blue")),end_color(QColor("green")), pause_color(QColor("yellow")),mark_color(QColor("pink"))
    {
        color = basic_color;
        builder = new sd::DiagramBuilder<T>(sorts::get_max(state->array), width, height, state->array.size());
        create_new_scene(state);
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
    void MyGraphicsView<T>::create_new_scene(MementoSorting<T>* state, const QString& add_to_end, bool the_end)
    {
        builder->clear();
        if(the_end) color = end_color;
        builder->set_color(color);
        for(std::size_t i = 0; i < state->array.size(); i++)
        {
            if(state->marks[i]) builder->set_color(mark_color);
            else builder->set_color(color);
            builder->append_column(state->array[i]);
        }
        builder->add_description(title);
        QString des = "size: " + QString::number(state->array.size());
        builder->add_description(des);
        if(note.size() > 0) builder->add_description(note);
        if(add_to_end.size() > 0) builder->add_description(add_to_end);
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
