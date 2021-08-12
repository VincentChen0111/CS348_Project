#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QLabel>
#include <QStackedWidget>
#include <QTabWidget>
#include <QSqlDatabase>
#include <QSqlError>
#include <QMessageBox>
#include <iostream>
#include <QSqlTableModel>
#include <QDebug>
#include <QSqlRecord>
#include <QSqlField>
#include <QVariant>
#include <QSqlQuery>
#include <QCloseEvent>
#include <QItemSelectionModel>
#include <QString>
#include <vector>
#include <QDate>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->adminFail->setVisible(false);
    ui->regiFail->setVisible(false);
    ui->userFail->setVisible(false);
    ui->stackedWidget->setCurrentWidget(ui->login);
    qDebug() << QDate::currentDate().toString(Qt::ISODate);

    connectMysql(3);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::connectMysql(int type){
    db = new QSqlDatabase();
    *db = QSqlDatabase::addDatabase("QMYSQL");

    db->setHostName("cs348-project.c56bjewfihhr.us-east-2.rds.amazonaws.com");
    db->setDatabaseName("shoppingApp");

    switch (type) {
        case 1:
            db->setUserName("admin");
            db->setPassword("123456");
            break;
        case 2:
            db->setUserName("customer");
            db->setPassword("123456789");
            break;
        case 3:
            db->setUserName("UsrCtrl");
            db->setPassword("123456");
            break;
        default:
            break;
    }



    if(!db->open()){
        QMessageBox::warning(this, "Error", db->lastError().text());
        return;
    }
}

void MainWindow::initDataUser(){
    qmod = new QSqlQueryModel(this);
    qmod->setQuery("select cname from Categories");
    ui->userCat->setModel(qmod);
    ui->userTableView->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->userTableView->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->userTableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->userTableView->resizeColumnsToContents();
    ui->itemVal->setDisabled(true);
    ui->addCart->setDisabled(true);
}

void MainWindow::initHelper(QTableView *u, QSqlTableModel *mod){
    mod->setEditStrategy(QSqlTableModel::OnManualSubmit);
    mod->select();
    u->setModel(mod);
    u->setEditTriggers(QAbstractItemView::NoEditTriggers);
    u->setSelectionBehavior(QAbstractItemView::SelectRows);
    u->resizeColumnsToContents();
    u->show();
}

void MainWindow::initDataAdmin(){
    tmod = new QSqlTableModel(this);
    tmod->setEditStrategy(QSqlTableModel::OnManualSubmit);
    tmod->setTable("Categories");
    tmod->select();
    ui->updateView->setModel(tmod);
    ui->updateView->setEditTriggers(QAbstractItemView::DoubleClicked);
    ui->updateView->resizeColumnsToContents();
    ui->updateView->show();
    ui->updateViewSelect->setCurrentText("Categories");

    ui->updateToDiscount->setDisabled(true);

    //qDebug() << "where";
    tmod2 = new QSqlTableModel(this);
    tmod3 = new QSqlTableModel(this);
    tmod4 = new QSqlTableModel(this);

    //qDebug() << "ere";
    tmod2->setTable("Categories");
    tmod3->setTable("Items");
    tmod4->setTable("SubCategories");
    //qDebug() << "there";
    initHelper(ui->catCatView, tmod2);
    initHelper(ui->catItemView, tmod3);
    initHelper(ui->catSubView, tmod4);
    ui->catCatView->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->catCatView->show();
    ui->updateRmExpired->hide();


}



void MainWindow::on_regiConf_clicked()
{
    QSqlTableModel regiU, U;
    regiU.setTable("RegisteredUsers");
    U.setTable("Users");
    regiU.setEditStrategy(QSqlTableModel::OnManualSubmit);
    U.setEditStrategy(QSqlTableModel::OnManualSubmit);

    QString name = ui->regiName->text(), pw = ui->regiPw->text();

    regiU.setFilter(QString("username = '%1'").arg(name));
    //qDebug() << QString("username = '%1'").arg(name);

    regiU.select();
    if(regiU.rowCount() > 0) {
        ui->regiFail->setVisible(false);
        ui->regiFail->setVisible(true);
        return;
    }

    ui->regiFail->setVisible(false);
    regiU.setTable("RegisteredUsers");
    regiU.select();
    int id = regiU.rowCount();
    qDebug() << QString("%1").arg(id);
    U.insertRows(0,1);
    U.setData(U.index(0,0), id);
    U.submitAll();


    regiU.insertRows(0,1);
    regiU.setData(regiU.index(0,0), id);
    regiU.setData(regiU.index(0,1), name);
    regiU.setData(regiU.index(0,2), pw);
    regiU.setData(regiU.index(0,3), 0);
    regiU.submitAll();

}


void MainWindow::on_adminLogin_2_clicked()
{
    QSqlQueryModel *regiU = new QSqlQueryModel(this);
    QString name = ui->adminName->text(), pw = ui->adminPw_2->text();

    regiU->setQuery(QString("select * from RegisteredUsers where username = '%1' and password = '%2' and isAdmin = 1").arg(name).arg(pw));
    qDebug() << QString("select * from RegisteredUsers where username = '%1' and password = '%2' and isAdmin = 1").arg(name).arg(pw);
    if(regiU->rowCount() == 0){
        ui->adminFail->setVisible(true);
        return;
    }
    uid = uid = regiU->record(0).field(0).value().toInt();

    db->close();
    free(db);
    connectMysql(1);

    initDataAdmin();
    ui->stackedWidget->setCurrentWidget(ui->AdminMenu);
    ui->pageTitle->setText(QString("Welcome, admin '%1'").arg(name));
}


void MainWindow::on_userLogin_2_clicked()
{
    QSqlQueryModel *regiU = new QSqlQueryModel(this);
    QString name = ui->userName->text(), pw = ui->userPw->text();

    regiU->setQuery(QString("select * from RegisteredUsers where username = '%1' and password = '%2' and isAdmin = 0").arg(name).arg(pw));
    qDebug() << QString("select * from RegisteredUsers where username = '%1' and password = '%2' and isAdmin = 0").arg(name).arg(pw);
    if(regiU->rowCount() == 0){
        ui->userFail->setVisible(true);
        return;
    }
    uid = regiU->record(0).field(0).value().toInt();

    db->close();
    free(db);
    connectMysql(2);

    ui->stackedWidget->setCurrentWidget(ui->UsrMenu);
    ui->pageTitle->setText(QString("Welcome, user '%1'").arg(name));
    initDataUser();
}


void MainWindow::on_guestLogin_2_clicked()
{
    QSqlTableModel U;
    U.setTable("Users");
    U.setSort(0,Qt::DescendingOrder);
    U.select();
    int id = U.record(0).field(0).value().toInt() + 1;
    U.insertRows(0,1);
    U.setData(U.index(0,0),id);
    U.submitAll();
    uid = id;

    db->close();
    free(db);
    connectMysql(2);

    ui->stackedWidget->setCurrentWidget(ui->UsrMenu);
    ui->pageTitle->setText(QString("Welcome, guest '%1'").arg(id));
    initDataUser();
}

void MainWindow::closeEvent(QCloseEvent *e)
{

    //qDebug() << uid;
    if(uid >= 10000){
        QSqlQuery U ;
        if(!U.exec(QString("delete from IsInCart where uid = %1").arg(uid))){
            QMessageBox::critical(0,
            QObject::tr("Database Error"),
            U.lastError().text());
        }
        if(!U.exec(QString("delete from Users where uid = %1").arg(uid))){
            QMessageBox::critical(0,
            QObject::tr("Database Error"),
            U.lastError().text());
        }
    }

    db->close();
    free(db);
    //qDebug("almost");
    e->accept();
}

void MainWindow::on_userCat_currentIndexChanged(const QString &arg1)
{
    if(arg1 == "All"){
        ui->userSubcat->clear();

    }
    else{
        ui->userSubcat->clear();
        QSqlQuery q;
        q.exec(QString("select scname from SubCategories join (select scid from IsSubsetOf join (select cid from Categories where cname = '%1') as temp where IsSubsetOf.cid = temp.cid) as temp2 where SubCategories.scid = temp2.scid;").arg(arg1));

        while(q.next()){
            QString name = q.value(0).toString();
            ui->userSubcat->addItem(name);
        }
    }
}



void MainWindow::on_userCatView_clicked()
{
    qmod2 = new QSqlQueryModel(this);
    ui->itemVal->setEnabled(true);
    ui->addCart->setEnabled(true);
    if(ui->userCat->currentText() == "All"){
        qmod2->setQuery("select * from Items");
        ui->userTableView->setModel(qmod2);
        ui->userTableView->show();

        return;
    }
    QString a1 = ui->userCat->currentText(), a2 = ui->userSubcat->currentText();

    qmod2->setQuery(QString("select * from Items inner join ( select IsMemberOf.iid from IsMemberOf inner join ( select SubCategories.scid from SubCategories where SubCategories.scname = '%1' ) as query_scid on IsMemberOf.scid = query_scid.scid ) as query_table on Items.iid = query_table.iid;").arg(a2));
    ui->userTableView->setModel(qmod2);
    ui->userTableView->show();
}

void MainWindow::on_userViewSale_clicked()
{
    qmod2 = new QSqlQueryModel(this);
    ui->itemVal->setEnabled(true);
    ui->addCart->setEnabled(true);

    qmod2->setQuery("select * from ItemsOnSale");
    ui->userTableView->setModel(qmod2);
    ui->userTableView->show();

    return;

}


void MainWindow::on_itemVal_valueChanged(int arg1)
{
    QItemSelectionModel *smod = ui->userTableView->selectionModel();

    QModelIndexList lst = smod->selectedRows();
    //qDebug() << 1;

    if(lst.empty()){
        QMessageBox::warning(this, "Error", "please select an item first");
        return;
    }

    int iid = qmod2->record(lst.at(0).row()).value(0).toInt();

    QSqlQuery q;
    if(!q.exec(QString("select stock from Items where iid = %1").arg(iid))){
        QMessageBox::warning(this, "Error", q.lastError().text());
    }
    q.next();
    int remain = q.value(0).toInt();
    qDebug() << remain;

    if(arg1 > remain){
        ui->itemVal->setValue(remain);
        return;
    }

}


void MainWindow::on_addCart_clicked()
{
    QSqlQuery q1,q2,q3;
    QItemSelectionModel *smod = ui->userTableView->selectionModel();

    QModelIndexList lst = smod->selectedRows();
    if(lst.empty()){
        QMessageBox::warning(this, "Error", "please select an item first");
        return;
    }

    QSqlRecord rc = qmod2->record(lst.at(0).row());
    int iid = rc.value(0).toInt(), val = ui->itemVal->value();
    QString sql = QString("select * from IsInCart where uid = %1 and iid = %2;").arg(uid).arg(iid);
    q1.exec(sql);

    if(q1.size() == 0){
        q2.exec(QString("insert into IsInCart values (%1, %2, %3);").arg(iid).arg(uid).arg(val));
    }
    else{
        q1.next();
        val = val + q1.record().value(2).toInt();
        qDebug() << val;
        q3.exec(QString("update IsInCart set IsInCart.quantity = %1 where IsInCart.iid = %2 and IsInCart.uid = %3;").arg(val).arg(iid).arg(uid));
    }


}


void MainWindow::on_searchButton_clicked()
{
    qmod2 = new QSqlQueryModel(this);
    qmod2->setQuery(QString("select * from Items where Items.name like '%%1%';").arg(ui->searchLnEdit->text()));
    ui->userTableView->setModel(qmod2);
    ui->userTableView->show();
    ui->itemVal->setEnabled(true);
    ui->addCart->setEnabled(true);
}




void MainWindow::on_displayCart_clicked()
{

    ui->itemVal->setEnabled(false);
    ui->addCart->setEnabled(false);

    qmod3 = new QSqlQueryModel(this);
    qmod3->setQuery(QString("select Items.iid, name, quantity from Items join (select * from IsInCart where uid = '%1') as t1 where Items.iid = t1.iid;").arg(uid));
    ui->userTableView->setModel(qmod3);
    ui->userTableView->show();

}


void MainWindow::on_cartUpdateButton_clicked()
{
    int iid = ui->cartIdLnEdit->text().toInt(), quantity = ui->cartQuantityLnEdit->text().toInt();
    QSqlQuery q,q1;
    q.exec(QString("select * from IsInCart where uid = %1 and iid = %2").arg(uid).arg(iid));


    if(q.size() == 0) {
        QMessageBox::warning(this, "Error", "please select the item first");
        return;
    }

    q1.exec(QString("update IsInCart set IsInCart.quantity = %1 where IsInCart.iid = %2 and IsInCart.uid = %3;").arg(quantity).arg(iid).arg(uid));
    ui->displayCart->click();
}


void MainWindow::on_checkOutButton_clicked()
{
    QSqlQuery q,q1,q2;
    q.exec(QString("select * from IsInCart where uid = %1").arg(uid));

    while(q.next()){
        int iid = q.value(0).toInt(), quant = q.value(2).toInt();
        //qDebug() << iid;
        //qDebug() << quant;
        q1.exec(QString("select * from Items where iid = %1").arg(iid));
        q1.next();
        int remain = q1.value(3).toInt() - quant;
        //qDebug() << remain;
        if(remain < 0){
            QMessageBox::warning(this, "Error", QString("please confirm the item with id %1 in your cart does not exceed stock.").arg(q.value(0).toInt()));
            return;
        }

        q2.exec(QString("Update Items set Items.stock = '%1' where Items.iid = '%2';").arg(remain).arg(iid));
    }
    this->close();


}


void MainWindow::on_updateCommit_clicked()
{
    if(!tmod->submitAll()){
        QMessageBox::warning(this, "Error", tmod->lastError().text());
    }

}


void MainWindow::on_updateViewSelect_currentIndexChanged(const QString &arg1)
{
    tmod->setTable(arg1);
    tmod->select();
    ui->updateView->show();
    if(arg1 != "Items"){
        ui->updateToDiscount->setDisabled(true);
    }
    else ui->updateToDiscount->setEnabled(true);

    if(arg1 != "ItemsOnSale"){
        ui->updateRmExpired->hide();
    }
    else ui->updateRmExpired->show();

}


void MainWindow::on_updateCancel_clicked()
{
    tmod->revertAll();
    tmod->submitAll();
}


void MainWindow::on_updateAdd_clicked()
{
    QSqlRecord rc = tmod->record();
    int row = tmod->rowCount();
    tmod->insertRecord(row, rc);

}

void MainWindow::delSub(std::vector<int> &scid){
    QSqlQuery q1,q2,q3;

    for(int id : scid){
        q1.exec(QString("DELETE FROM IsMemberOf where IsMemberOf.scid = %1;").arg(id));
        q3.exec(QString("DELETE FROM IsSubsetOf where IsSubsetOf.scid = %1;").arg(id));
        q2.exec(QString("DELETE FROM SubCategories where SubCategories.scid = %1;").arg(id));

    }

}

void MainWindow::on_updateDelete_clicked()
{
    QSqlQuery q1,q2,q3,q4;
    QItemSelectionModel *ismod = ui->updateView->selectionModel();
    QModelIndexList lst = ismod->selectedRows();
    std::vector<int> id, subid;
    for(int i = 0; i < lst.size(); i++){
        id.emplace_back(tmod->record(lst.at(i).row()).field(0).value().toInt());
    }
    if(ui->updateViewSelect->currentText() == "Items"){
        for(int iid : id){
            q3.exec(QString("DELETE FROM ItemsOnSale where iid = %1;").arg(iid));
            q3.exec(QString("DELETE FROM IsInCart where iid = %1;").arg(iid));
            q1.exec(QString("DELETE FROM IsMemberOf where IsMemberOf.iid = %1;").arg(iid));
            q2.exec(QString("DELETE FROM Items where iid = %1;").arg(iid));
        }

    }
    else if(ui->updateViewSelect->currentText() == "Categories"){
        for(int cid : id){
            q2.exec(QString("Select * FROM IsSubsetOf where cid = %1;").arg(cid));
            while(q2.next()){
                subid.emplace_back(q2.value(1).toInt());
            }

        }
        delSub(subid);

        for(int cid : id){
            q1.exec(QString("DELETE FROM Categories where cid = %1;").arg(cid));
        }


    }
    else if(ui->updateViewSelect->currentText() == "SubCategories"){
        delSub(id);
    }
    else{
         for(int iid : id){
             q1.exec(QString("delete from ItemsOnSale where iid = %1").arg(iid));
         }
    }

    tmod->setTable(ui->updateViewSelect->currentText());
    tmod->select();
    ui->updateView->show();

}


void MainWindow::on_updateToDiscount_clicked()
{
    QSqlQuery q1;
    QItemSelectionModel *ismod = ui->updateView->selectionModel();
    QModelIndexList lst = ismod->selectedRows();
    std::vector<int> id;
    for(int i = 0; i < lst.size(); i++){
        id.emplace_back(tmod->record(lst.at(i).row()).field(0).value().toInt());
    }



    for(int iid : id){
        //qDebug() << iid;
        if(!q1.exec(QString("insert into ItemsOnSale values(%1, 50, '%2');").arg(iid).arg(QDate::currentDate().toString(Qt::ISODate)))){
            QMessageBox::warning(this, "Error", q1.lastError().text());
        }
        else{
            //QMessageBox::warning(this, "Finish",QString("insert into ItemsOnSale values(%1, 50, '%2');").arg(iid).arg(QDate::currentDate().toString(Qt::ISODate)) );
        }
    }

    tmod->setTable("ItemsOnSale");
    tmod->select();
    ui->updateView->show();
    ui->updateViewSelect->setCurrentText("ItemsOnSale");
}



void MainWindow::on_catItemToSub_clicked()
{
    QSqlQuery q1,q2;
    QItemSelectionModel *ismod1 = ui->catItemView->selectionModel();
    QModelIndexList lst1 = ismod1->selectedRows();
    QItemSelectionModel *ismod2 = ui->catSubView->selectionModel();
    QModelIndexList lst2 = ismod2->selectedRows();
    std::vector<int> id;
    int subid;

    if(lst2.size() != 1){
        QMessageBox::warning(this, "Error", "Please select exactly one subcategory");
        return;
    }

    for(int i = 0; i < lst1.size(); i++){
        //qDebug() << tmod3->record(lst1.at(i).row()).field(0).value().toInt();
        id.emplace_back(tmod3->record(lst1.at(i).row()).field(0).value().toInt());
    }

    subid = tmod4->record(lst2.at(0).row()).field(0).value().toInt();
    //qDebug() << subid;


    for(int iid : id){
        qDebug() << iid << " " << subid;

        if(!q2.exec(QString("select * from IsMemberOf where iid = %1;").arg(iid))){
            QMessageBox::warning(this, "Error", q2.lastError().text());
            return;
        }
        if(q2.size() == 0){
            q1.exec(QString("insert into IsMemberOf values (%1, %2);").arg(iid).arg(subid));
            return;
        }

        if(!q1.exec(QString("update IsMemberOf set scid = %1 where iid = %2;").arg(subid).arg(iid))){
            QMessageBox::warning(this, "Error", q1.lastError().text());
            return;
        }
    }


}


void MainWindow::on_catSubToCat_clicked()
{
    QSqlQuery q1,q2;
    QItemSelectionModel *ismod1 = ui->catSubView->selectionModel();
    QModelIndexList lst1 = ismod1->selectedRows();
    QItemSelectionModel *ismod2 = ui->catCatView->selectionModel();
    QModelIndexList lst2 = ismod2->selectedRows();
    std::vector<int> id;
    int cid;

    if(lst2.size() != 1){
        QMessageBox::warning(this, "Error", "Please select exactly one category");
        return;
    }

    for(int i = 0; i < lst1.size(); i++){
        id.emplace_back(tmod4->record(lst1.at(i).row()).field(0).value().toInt());
    }

    cid = tmod2->record(lst2.at(0).row()).field(0).value().toInt();

    for(int iid : id){
        qDebug() << iid << " " << cid;

        if(!q2.exec(QString("select * from IsSubsetOf where scid = %1;").arg(iid))){
            QMessageBox::warning(this, "Error", q2.lastError().text());
            return;
        }
        if(q2.size() == 0){
            q1.exec(QString("insert into IsSubsetOf values (%1, %2);").arg(cid).arg(iid));
            return;
        }
        if(!q1.exec(QString("update IsSubsetOf set IsSubsetOf.cid = %1 where IsSubsetOf.scid = %2;").arg(cid).arg(iid))){
            QMessageBox::warning(this, "Error", q1.lastError().text());
            return;
        }
    }
}


void MainWindow::on_updateRmExpired_clicked()
{
    QDate cur = QDate::currentDate();

    int size = tmod->rowCount() - 1;
    for(int i = size; i >= 0; i--){
        QSqlRecord rc = tmod->record(i);
        if(rc.value(2).toDate() < cur){
            tmod->removeRow(i);
            tmod->submitAll();
        }
    }
}


void MainWindow::on_refresh_clicked()
{
    tmod2->setTable("Categories");
    tmod3->setTable("Items");
    tmod4->setTable("SubCategories");
    //qDebug() << "there";
    initHelper(ui->catCatView, tmod2);
    initHelper(ui->catItemView, tmod3);
    initHelper(ui->catSubView, tmod4);
    ui->catCatView->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->catCatView->show();
    ui->updateRmExpired->hide();
}

