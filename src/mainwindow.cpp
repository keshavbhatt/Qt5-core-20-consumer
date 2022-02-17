#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QFileDialog>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
  ui->setupUi(this);
}

MainWindow::~MainWindow() { delete ui; }

void MainWindow::on_openDialogPb_clicked() {
  bool useNativeDialog = ui->nativecheckBox->isChecked();
  QStringList files;
  if (useNativeDialog) {
    files =
        QFileDialog::getOpenFileNames(this, "Select one or more files to open",
                                      "/home", "Images (*.png *.xpm *.jpg)");
  } else {
    files = QFileDialog::getOpenFileNames(
        this, "Select one or more files to open", "/home",
        "Images (*.png *.xpm *.jpg)", nullptr,
        QFileDialog::DontUseNativeDialog);
  }
  qDebug() << files;
}

void MainWindow::on_saveDialogPb_clicked() {
  bool useNativeDialog = ui->nativecheckBox->isChecked();
  QString fileName;
  if (useNativeDialog) {
    fileName =
        QFileDialog::getSaveFileName(this, tr("Save File"), "untitled.png",
                                     tr("Images (*.png *.xpm *.jpg)"));
  } else {
    fileName = QFileDialog::getSaveFileName(
        this, tr("Save File"), "untitled.png", tr("Images (*.png *.xpm *.jpg)"),
        nullptr, QFileDialog::DontUseNativeDialog);
  }
  qDebug() << fileName;
}

void MainWindow::on_nativecheckBox_stateChanged(int arg1) {
  qDebug() << QString(arg1 ? "useQtNative" : "useSystemNative");
}
