#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "calculator.h"
#include <QMessageBox>
#include <QDebug>
#include <QIcon>
#include <QObject>

OprandType EvaluateExpression(OpcharType * const s, OprandType ans, OprandType myrand, bool *flag);

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle(tr("MyCalculator"));
    setWindowIcon(QIcon(tr(":/image/icon")));
    setWindowFlags(Qt::WindowCloseButtonHint);
    //setWindowFlags(Qt::Tool);
    //setWindowFlags(Qt::SplashScreen); //极简

    ui->lineEdit->setPlaceholderText("Input your expression");
    ui->textBrowser->setPlaceholderText("Answer");
   // ui->lineEdit_2->setPlaceholderText("Answer");
    setStyleSheet("background-color:rgb(255,255,255)");
    //setWindowFlags(Qt::WindowStaysOnTopHint);
    setGeometry(200,200,230,57);
   // ui->textBrowser->installEventFilter(this);
   // ui->lineEdit_2->installEventFilter(this);
   // ui->textBrowser->setFocusPolicy(Qt::ClickFocus);
   // ui->lineEdit_2->setFocusPolicy(Qt::ClickFocus);
    ui->dateTimeEdit->setDate(QDate::currentDate());
    ui->dateTimeEdit->setTime(QTime::currentTime());
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_lineEdit_editingFinished()
{
    QString inputstring = ui->lineEdit->text();
    bool flag;
    char*  string;
    QByteArray ba = inputstring.toLatin1(); // must
    string = ba.data();
    if(strcmp(string, "MissLi"))
    {
        OprandType result =  EvaluateExpression(string, 0, 0, &flag);
        ui->textBrowser->setText(QString::number(result));
    //    ui->lineEdit_2->setText(QString::number(result));
    }
    else
    {
        ui->textBrowser->setText(tr("Hope"));
    }
}

bool MainWindow::eventFilter(QObject* watched,QEvent *event)
{
    if(watched == ui->textBrowser)
    {
        if (event->type()==QEvent::FocusIn)     //然后再判断控件的具体事件 (这里指获得焦点事件)
        {
        }
        else if (event->type()==QEvent::FocusOut)    // 这里指 lineEdit1 控件的失去焦点事件
        {
            QPalette p=QPalette();
            p.setColor(QPalette::Base,Qt::white);
            ui->textBrowser->setPlaceholderText("Answer");
        }
    }
    /*
    if(watched == ui->lineEdit_2)
    {
        if (event->type()==QEvent::FocusIn)     //然后再判断控件的具体事件 (这里指获得焦点事件)
        {
        }
        else if (event->type()==QEvent::FocusOut)    // 这里指 lineEdit1 控件的失去焦点事件
        {
            QPalette p=QPalette();
            p.setColor(QPalette::Base,Qt::white);
            ui->lineEdit_2->setPlaceholderText("Answer");
        }
    }
*/
    return true;
}
