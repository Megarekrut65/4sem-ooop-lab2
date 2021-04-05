#ifndef MYGRAPHICSVIEW_H
#define MYGRAPHICSVIEW_H
#include "diagram_builder.h"
#include "Sorts/all_sorts.h"
#include "memento_sorting.h"

using namespace ms;

namespace sd
{
    /*!
    *   \brief Template class to create window with diagram by number array. See ms::MementoSorting - use as number array
    *
    *   You can open window as new window or get scene and add diagram to opened window.
    *
    *   You can use object of class a lot of times. Just call function clear.
    */
    template<typename T>
    class MyGraphicsView
    {
    private:
        QString title;/*!< Name of window */
        QString note;/*!< Text in bottom of window */
        QGraphicsView* view;/*!< The window */
        DiagramBuilder<T>* builder;/*!< Builder to create diagram */
        const size_t width;/*!< Width of window */
        const size_t height;/*!< Height of window */
        QColor color;/*!< Current color of columns of diagram */
        const QColor basic_color;/*!< Standart color of diagram */
        const QColor end_color;/*!< Color to show that it is in the end */
        const QColor pause_color;/*!< Color to show that it is paused */
        const QColor mark_color; /*!< Color to mark some columns to show it */
    public:  
        /*!
        * \brief Sets all parameters to create diagram
        *
        * Also creates first diagram by state.
        *
        * If you open diagram in new window that there will be title else title is unused.
        */
        MyGraphicsView(const QString& title,const QString& note, MementoSorting<T>* state, size_t width = 800,size_t height = 600);
        /*!
        *   \brief Opens diagram in new window
        */
        void show();
        /*!
        *   \brief Closes the opened diagram
        */
        void close();
        /*!
        *   \brief Creates new diagram by state
        *
        *   Clears old scene(diagram) and add new state to it. Also adds other notes to the end of note.
        *
        *   \param state - object with number array and mark array. There is mark array to mark some items
        *   \param add_to_end - text to add to the end of notes
        *   \param the_end - if true then color will be end_color
        */
        void create_new_scene(MementoSorting<T>* state,const QString& add_to_end = "", bool the_end = false);
        /*!
        *   \returns view - window with diagram
        */
        QGraphicsView* get_view();
        /*!
        *   \returns scene - diagram
        */
        QGraphicsScene* get_scene();
        /*!
        *   \brief Sets pause color
        */
        void set_pause_color();
        /*!
        *   \brief Sets basic color
        */
        void set_start_color();
        /*!
        *   \brief Clears all data of window
        */
        void clear();
        /*!
        *   \brief Deletes all pointers
        */
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
