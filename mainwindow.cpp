#include "mainwindow.h"
#include "ui_mainwindow.h"

double num_first;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->pb__0,SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->pushButton_1,SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->pushButton2,SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->pushButton__3,SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->pushButton__4,SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->pushButton__5,SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->pushButton__6,SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->pushButton_7,SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->pushButton__8,SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->pushButton_9,SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->pluminus,SIGNAL(clicked()),this,SLOT(operations()));
    connect(ui->procent,SIGNAL(clicked()),this,SLOT(operations()));
    connect(ui->deleniye,SIGNAL(clicked()),this,SLOT(math_operations()));
    connect(ui->plus,SIGNAL(clicked()),this,SLOT(math_operations()));
    connect(ui->minus,SIGNAL(clicked()),this,SLOT(math_operations()));
    connect(ui->umnozh,SIGNAL(clicked()),this,SLOT(math_operations()));
    ui->deleniye->setCheckable(true);
    ui->minus->setCheckable(true);
    ui->plus->setCheckable(true);
    ui->umnozh->setCheckable(true);


  }

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::digits_numbers()
{
    QPushButton *button = (QPushButton*)sender();
    double numbers;
    QString new_label;
    if(ui->result_show->text().contains(".")&& button->text()=="0"){
        new_label = ui->result_show->text()+button->text();
    }else{
    numbers = (ui->result_show->text()+button->text()).toDouble();
    new_label = QString::number(numbers, 'g', 15);
    }
    ui->result_show->setText(new_label);

}


void MainWindow::on_tochka_clicked()
{
    if(!ui->result_show->text().contains('.'))
     ui->result_show->setText(ui->result_show->text()+".");
}

void MainWindow::operations()
{
    QPushButton *button = (QPushButton*)sender();
    double numbers;
    QString new_label;

    if(button->text() == "+/-"){
    numbers = (ui->result_show->text()).toDouble();
    numbers = numbers * -1;
    new_label = QString::number(numbers, 'g', 15);
    ui->result_show->setText(new_label);
    }
    else if(button->text() == "%"){
    numbers = (ui->result_show->text()).toDouble();
    numbers = numbers * 0.01;
    new_label = QString::number(numbers, 'g', 15);
    ui->result_show->setText(new_label);
    }
}

void MainWindow::math_operations()
{

    QPushButton *button = (QPushButton*)sender();

    num_first = ui->result_show->text().toDouble();
    ui->result_show->setText("");
    button->setChecked(true);
}

void MainWindow::on_AC_clicked()
{
    ui->minus->setChecked(false);
    ui->plus->setChecked(false);
    ui->deleniye->setChecked(false);
    ui->umnozh->setChecked(false);
    ui->result_show->setText("0");
}



void MainWindow::on_rovno_clicked()
{

   double labelNumber, num_second;
   QString new_label;

   num_second = ui->result_show->text().toDouble();

   if(ui->plus->isChecked()){
        labelNumber = num_first + num_second;
        new_label = QString::number(labelNumber, 'g', 15);
        ui->result_show->setText(new_label);
        ui->plus->setChecked(false);
}
   else if (ui->minus->isChecked()){
       labelNumber = num_first - num_second;
       new_label = QString::number(labelNumber, 'g', 15);
       ui->result_show->setText(new_label);
       ui->minus->setChecked(false);
}
   else if (ui->umnozh->isChecked()){
       labelNumber = num_first * num_second;
       new_label = QString::number(labelNumber, 'g', 15);
       ui->result_show->setText(new_label);
       ui->umnozh->setChecked(false);
}
   else if (ui->deleniye->isChecked()){
       if(num_second == 0){
            ui->result_show->setText("0");
       }else {
       labelNumber = num_first / num_second;
       new_label = QString::number(labelNumber, 'g', 15);
       ui->result_show->setText(new_label);
       ui->deleniye->setChecked(false);
}
}
}
