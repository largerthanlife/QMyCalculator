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
    OprandType result =  EvaluateExpression(string, 0, 0, &flag);
    ui->textBrowser->setText(QString::number(result));
}
