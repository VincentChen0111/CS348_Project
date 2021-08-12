#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSqlDatabase>
#include <QSqlQueryModel>
#include <QSqlTableModel>
#include <vector>
#include <QTableView>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void connectMysql(int type);
    void initDataAdmin();
    void initDataUser();
    void delSub(std::vector<int> &scid);
    void initHelper(QTableView *u, QSqlTableModel *mod);

private slots:
    void on_regiConf_clicked();

    void on_adminLogin_2_clicked();

    void on_userLogin_2_clicked();

    void on_guestLogin_2_clicked();

    void on_userCat_currentIndexChanged(const QString &arg1);


    void on_userCatView_clicked();

    void on_itemVal_valueChanged(int arg1);

    void on_addCart_clicked();

    void on_searchButton_clicked();


    void on_displayCart_clicked();

    void on_cartUpdateButton_clicked();

    void on_checkOutButton_clicked();

    void on_updateCommit_clicked();

    void on_updateViewSelect_currentIndexChanged(const QString &arg1);

    void on_updateCancel_clicked();

    void on_updateAdd_clicked();

    void on_updateDelete_clicked();

    void on_updateToDiscount_clicked();

    void on_userViewSale_clicked();

    void on_catItemToSub_clicked();

    void on_catSubToCat_clicked();

    void on_updateRmExpired_clicked();

    void on_refresh_clicked();

private:
    Ui::MainWindow *ui;
    QSqlDatabase *db;
    int uid;
    QSqlQueryModel *qmod, *qmod2, *qmod3, *qmod4;
    QSqlTableModel *tmod, *tmod2, *tmod3, *tmod4;

protected:
    void closeEvent(QCloseEvent *e);
};
#endif // MAINWINDOW_H
