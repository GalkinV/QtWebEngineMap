#include <QWidget>
#include <QWebEngineView>
#include <QQuickItem>
#include <QDebug>
#include <QTextEdit>

#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    webobj = new WebClass();
    channel = new QWebChannel(this);
    channel->registerObject("server", webobj);

    ui->webEngineView->page()->setWebChannel(channel);

    ui->webEngineView->page()->load(QUrl("qrc:///static/drawAndEdit.html"));

    connect(ui->pushButton, SIGNAL(released()), this, SLOT(handleButtonReleased()));
    connect(this, SIGNAL(sendWkt(QString)), webobj, SLOT(catchQtWkt(QString)));
    connect(webobj, SIGNAL(wktToQt(QString)), ui->textEdit, SLOT(setText(QString)));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::handleButtonReleased()
{
    QString wkt = ui->textEdit->toPlainText();
    if(!wkt.isEmpty()){
        emit sendWkt(wkt);
    }
}
