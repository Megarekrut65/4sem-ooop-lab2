#include "algorithms_efficiency_window.h"
#include "ui_algorithms_efficiency_window.h"

algorithms_efficiency_window::algorithms_efficiency_window(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::algorithms_efficiency_window)
{
    ui->setupUi(this);
}

algorithms_efficiency_window::~algorithms_efficiency_window()
{
    delete ui;
}

QVector<int> algorithms_efficiency_window::random()
{
    QVector<int> result;
    for(int i = 0; i < ui->count_spinBox->value(); i++)
    {
        result.push_back(QRandomGenerator::global()->generate()%32000);
    }
    return result;
}

QVector<int> algorithms_efficiency_window::atleast_sorted_in_order()
{
    QVector<int> result;
    for(int i = 0; i < ui->count_spinBox->value(); i++)
    {
        result.push_back(i);
    }
    int index = (8*result.size())/10;//80% of item will be inorder
    for(int j = index; j < result.size(); j++)
    {
        int temp = result.takeAt(j);
                //ui->values_listWidget->takeItem(j);
        //ui->values_listWidget->insertItem(QRandomGenerator::global()->generate()%(size - index) + index, temp);
        result.push_back(temp);
    }
    /*for(int i = 0; i< result.size(); i++)
    {
        QString test = QString::number(result[i]);

        qDebug() << test;
    }*/
    return result;
}

QVector<int> algorithms_efficiency_window::atleast_sorted_in_reverse_order()
{
    QVector<int> result;
    for(int i = ui->count_spinBox->value(); i >= 0; i--)
    {
        result.push_back(i);
    }
    int index = (8*result.size())/10;//80% of item will be inorder
    for(int j = index; j < result.size(); j++)
    {
        int temp = result.takeAt(j);
                //ui->values_listWidget->takeItem(j);
        //ui->values_listWidget->insertItem(QRandomGenerator::global()->generate()%(size - index) + index, temp);
        result.push_back(temp);
    }
    /*for(int i = 0; i< result.size(); i++)
    {
        QString test = QString::number(result[i]);

        qDebug() << test;
    }*/
    return result;
}

void algorithms_efficiency_window::on_start_pushButton_clicked()
{
    //this->random();
    this->atleast_sorted_in_reverse_order();
}
