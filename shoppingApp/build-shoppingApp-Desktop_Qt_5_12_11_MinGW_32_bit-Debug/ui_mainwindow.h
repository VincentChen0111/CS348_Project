/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.11
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout_7;
    QGridLayout *gridLayout;
    QSpacerItem *horizontalSpacer;
    QSpacerItem *horizontalSpacer_2;
    QLabel *pageTitle;
    QStackedWidget *stackedWidget;
    QWidget *login;
    QGridLayout *gridLayout_3;
    QTabWidget *tabWidget;
    QWidget *userLogin;
    QVBoxLayout *verticalLayout_3;
    QLabel *label_6;
    QLineEdit *userName;
    QLabel *label_7;
    QLineEdit *userPw;
    QSpacerItem *verticalSpacer_3;
    QPushButton *userLogin_2;
    QLabel *userFail;
    QWidget *adminLogin;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_3;
    QLineEdit *adminName;
    QLabel *label_4;
    QLineEdit *adminPw_2;
    QSpacerItem *verticalSpacer_2;
    QPushButton *adminLogin_2;
    QLabel *adminFail;
    QWidget *regi;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QLineEdit *regiName;
    QLabel *label_2;
    QLineEdit *regiPw;
    QSpacerItem *verticalSpacer;
    QPushButton *regiConf;
    QLabel *regiFail;
    QWidget *guestLogin;
    QGridLayout *gridLayout_6;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *guestLogin_2;
    QSpacerItem *horizontalSpacer_4;
    QWidget *AdminMenu;
    QGridLayout *gridLayout_4;
    QTabWidget *adminTab;
    QWidget *updateTab;
    QGridLayout *gridLayout_9;
    QTableView *updateView;
    QWidget *widget_2;
    QGridLayout *gridLayout_10;
    QPushButton *updateCommit;
    QComboBox *updateViewSelect;
    QPushButton *updateAdd;
    QPushButton *updateDelete;
    QPushButton *updateCancel;
    QPushButton *updateToDiscount;
    QPushButton *updateRmExpired;
    QWidget *catModifyTab;
    QVBoxLayout *verticalLayout_8;
    QWidget *widget_3;
    QHBoxLayout *horizontalLayout_2;
    QTableView *catItemView;
    QTableView *catSubView;
    QTableView *catCatView;
    QPushButton *refresh;
    QWidget *widget_4;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *catItemToSub;
    QPushButton *catSubToCat;
    QWidget *UsrMenu;
    QVBoxLayout *verticalLayout_5;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QTabWidget *userTab;
    QWidget *userView;
    QGridLayout *gridLayout_7;
    QGridLayout *gridLayout_2;
    QLabel *label_5;
    QVBoxLayout *verticalLayout_4;
    QLabel *label_9;
    QSpinBox *itemVal;
    QComboBox *userSubcat;
    QPushButton *userCatView;
    QLabel *label_8;
    QPushButton *addCart;
    QComboBox *userCat;
    QPushButton *userViewSale;
    QWidget *userSearch;
    QVBoxLayout *verticalLayout_6;
    QSpacerItem *verticalSpacer_6;
    QLabel *label_10;
    QLineEdit *searchLnEdit;
    QSpacerItem *verticalSpacer_5;
    QPushButton *searchButton;
    QSpacerItem *verticalSpacer_4;
    QLabel *label_11;
    QSpacerItem *verticalSpacer_7;
    QWidget *userCart;
    QGridLayout *gridLayout_8;
    QPushButton *displayCart;
    QLabel *label_12;
    QLineEdit *cartIdLnEdit;
    QLabel *label_13;
    QLineEdit *cartQuantityLnEdit;
    QPushButton *cartUpdateButton;
    QPushButton *checkOutButton;
    QTableView *userTableView;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1027, 701);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        verticalLayout_7 = new QVBoxLayout(centralwidget);
        verticalLayout_7->setObjectName(QString::fromUtf8("verticalLayout_7"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 0, 0, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_2, 0, 2, 1, 1);

        pageTitle = new QLabel(centralwidget);
        pageTitle->setObjectName(QString::fromUtf8("pageTitle"));
        QFont font;
        font.setPointSize(25);
        pageTitle->setFont(font);
        pageTitle->setLayoutDirection(Qt::LeftToRight);
        pageTitle->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(pageTitle, 0, 1, 1, 1);


        verticalLayout_7->addLayout(gridLayout);

        stackedWidget = new QStackedWidget(centralwidget);
        stackedWidget->setObjectName(QString::fromUtf8("stackedWidget"));
        QFont font1;
        font1.setPointSize(30);
        stackedWidget->setFont(font1);
        login = new QWidget();
        login->setObjectName(QString::fromUtf8("login"));
        QFont font2;
        font2.setPointSize(9);
        login->setFont(font2);
        gridLayout_3 = new QGridLayout(login);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        tabWidget = new QTabWidget(login);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        userLogin = new QWidget();
        userLogin->setObjectName(QString::fromUtf8("userLogin"));
        verticalLayout_3 = new QVBoxLayout(userLogin);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        label_6 = new QLabel(userLogin);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        verticalLayout_3->addWidget(label_6);

        userName = new QLineEdit(userLogin);
        userName->setObjectName(QString::fromUtf8("userName"));

        verticalLayout_3->addWidget(userName);

        label_7 = new QLabel(userLogin);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        verticalLayout_3->addWidget(label_7);

        userPw = new QLineEdit(userLogin);
        userPw->setObjectName(QString::fromUtf8("userPw"));
        userPw->setEchoMode(QLineEdit::Password);

        verticalLayout_3->addWidget(userPw);

        verticalSpacer_3 = new QSpacerItem(20, 120, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout_3->addItem(verticalSpacer_3);

        userLogin_2 = new QPushButton(userLogin);
        userLogin_2->setObjectName(QString::fromUtf8("userLogin_2"));

        verticalLayout_3->addWidget(userLogin_2);

        userFail = new QLabel(userLogin);
        userFail->setObjectName(QString::fromUtf8("userFail"));
        userFail->setAlignment(Qt::AlignCenter);

        verticalLayout_3->addWidget(userFail);

        tabWidget->addTab(userLogin, QString());
        adminLogin = new QWidget();
        adminLogin->setObjectName(QString::fromUtf8("adminLogin"));
        verticalLayout_2 = new QVBoxLayout(adminLogin);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        label_3 = new QLabel(adminLogin);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        verticalLayout_2->addWidget(label_3);

        adminName = new QLineEdit(adminLogin);
        adminName->setObjectName(QString::fromUtf8("adminName"));

        verticalLayout_2->addWidget(adminName);

        label_4 = new QLabel(adminLogin);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        verticalLayout_2->addWidget(label_4);

        adminPw_2 = new QLineEdit(adminLogin);
        adminPw_2->setObjectName(QString::fromUtf8("adminPw_2"));
        adminPw_2->setEchoMode(QLineEdit::Password);

        verticalLayout_2->addWidget(adminPw_2);

        verticalSpacer_2 = new QSpacerItem(20, 120, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout_2->addItem(verticalSpacer_2);

        adminLogin_2 = new QPushButton(adminLogin);
        adminLogin_2->setObjectName(QString::fromUtf8("adminLogin_2"));

        verticalLayout_2->addWidget(adminLogin_2);

        adminFail = new QLabel(adminLogin);
        adminFail->setObjectName(QString::fromUtf8("adminFail"));
        adminFail->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(adminFail);

        tabWidget->addTab(adminLogin, QString());
        regi = new QWidget();
        regi->setObjectName(QString::fromUtf8("regi"));
        verticalLayout = new QVBoxLayout(regi);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label = new QLabel(regi);
        label->setObjectName(QString::fromUtf8("label"));

        verticalLayout->addWidget(label);

        regiName = new QLineEdit(regi);
        regiName->setObjectName(QString::fromUtf8("regiName"));

        verticalLayout->addWidget(regiName);

        label_2 = new QLabel(regi);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        verticalLayout->addWidget(label_2);

        regiPw = new QLineEdit(regi);
        regiPw->setObjectName(QString::fromUtf8("regiPw"));

        verticalLayout->addWidget(regiPw);

        verticalSpacer = new QSpacerItem(20, 120, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout->addItem(verticalSpacer);

        regiConf = new QPushButton(regi);
        regiConf->setObjectName(QString::fromUtf8("regiConf"));

        verticalLayout->addWidget(regiConf);

        regiFail = new QLabel(regi);
        regiFail->setObjectName(QString::fromUtf8("regiFail"));
        regiFail->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(regiFail);

        tabWidget->addTab(regi, QString());
        guestLogin = new QWidget();
        guestLogin->setObjectName(QString::fromUtf8("guestLogin"));
        gridLayout_6 = new QGridLayout(guestLogin);
        gridLayout_6->setObjectName(QString::fromUtf8("gridLayout_6"));
        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_6->addItem(horizontalSpacer_3, 0, 0, 1, 1);

        guestLogin_2 = new QPushButton(guestLogin);
        guestLogin_2->setObjectName(QString::fromUtf8("guestLogin_2"));

        gridLayout_6->addWidget(guestLogin_2, 0, 1, 1, 1);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_6->addItem(horizontalSpacer_4, 0, 2, 1, 1);

        tabWidget->addTab(guestLogin, QString());

        gridLayout_3->addWidget(tabWidget, 0, 0, 1, 1);

        stackedWidget->addWidget(login);
        AdminMenu = new QWidget();
        AdminMenu->setObjectName(QString::fromUtf8("AdminMenu"));
        gridLayout_4 = new QGridLayout(AdminMenu);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        adminTab = new QTabWidget(AdminMenu);
        adminTab->setObjectName(QString::fromUtf8("adminTab"));
        adminTab->setFont(font2);
        updateTab = new QWidget();
        updateTab->setObjectName(QString::fromUtf8("updateTab"));
        gridLayout_9 = new QGridLayout(updateTab);
        gridLayout_9->setObjectName(QString::fromUtf8("gridLayout_9"));
        updateView = new QTableView(updateTab);
        updateView->setObjectName(QString::fromUtf8("updateView"));

        gridLayout_9->addWidget(updateView, 0, 0, 1, 1);

        widget_2 = new QWidget(updateTab);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));
        gridLayout_10 = new QGridLayout(widget_2);
        gridLayout_10->setObjectName(QString::fromUtf8("gridLayout_10"));
        updateCommit = new QPushButton(widget_2);
        updateCommit->setObjectName(QString::fromUtf8("updateCommit"));

        gridLayout_10->addWidget(updateCommit, 1, 4, 1, 1);

        updateViewSelect = new QComboBox(widget_2);
        updateViewSelect->addItem(QString());
        updateViewSelect->addItem(QString());
        updateViewSelect->addItem(QString());
        updateViewSelect->addItem(QString());
        updateViewSelect->setObjectName(QString::fromUtf8("updateViewSelect"));

        gridLayout_10->addWidget(updateViewSelect, 0, 1, 1, 1);

        updateAdd = new QPushButton(widget_2);
        updateAdd->setObjectName(QString::fromUtf8("updateAdd"));

        gridLayout_10->addWidget(updateAdd, 0, 2, 1, 1);

        updateDelete = new QPushButton(widget_2);
        updateDelete->setObjectName(QString::fromUtf8("updateDelete"));

        gridLayout_10->addWidget(updateDelete, 0, 3, 1, 1);

        updateCancel = new QPushButton(widget_2);
        updateCancel->setObjectName(QString::fromUtf8("updateCancel"));

        gridLayout_10->addWidget(updateCancel, 1, 1, 1, 1);

        updateToDiscount = new QPushButton(widget_2);
        updateToDiscount->setObjectName(QString::fromUtf8("updateToDiscount"));

        gridLayout_10->addWidget(updateToDiscount, 0, 4, 1, 1);

        updateRmExpired = new QPushButton(widget_2);
        updateRmExpired->setObjectName(QString::fromUtf8("updateRmExpired"));

        gridLayout_10->addWidget(updateRmExpired, 1, 2, 1, 2);


        gridLayout_9->addWidget(widget_2, 1, 0, 1, 1);

        adminTab->addTab(updateTab, QString());
        catModifyTab = new QWidget();
        catModifyTab->setObjectName(QString::fromUtf8("catModifyTab"));
        verticalLayout_8 = new QVBoxLayout(catModifyTab);
        verticalLayout_8->setObjectName(QString::fromUtf8("verticalLayout_8"));
        widget_3 = new QWidget(catModifyTab);
        widget_3->setObjectName(QString::fromUtf8("widget_3"));
        horizontalLayout_2 = new QHBoxLayout(widget_3);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        catItemView = new QTableView(widget_3);
        catItemView->setObjectName(QString::fromUtf8("catItemView"));

        horizontalLayout_2->addWidget(catItemView);

        catSubView = new QTableView(widget_3);
        catSubView->setObjectName(QString::fromUtf8("catSubView"));

        horizontalLayout_2->addWidget(catSubView);

        catCatView = new QTableView(widget_3);
        catCatView->setObjectName(QString::fromUtf8("catCatView"));

        horizontalLayout_2->addWidget(catCatView);


        verticalLayout_8->addWidget(widget_3);

        refresh = new QPushButton(catModifyTab);
        refresh->setObjectName(QString::fromUtf8("refresh"));

        verticalLayout_8->addWidget(refresh);

        widget_4 = new QWidget(catModifyTab);
        widget_4->setObjectName(QString::fromUtf8("widget_4"));
        horizontalLayout_3 = new QHBoxLayout(widget_4);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        catItemToSub = new QPushButton(widget_4);
        catItemToSub->setObjectName(QString::fromUtf8("catItemToSub"));

        horizontalLayout_3->addWidget(catItemToSub);

        catSubToCat = new QPushButton(widget_4);
        catSubToCat->setObjectName(QString::fromUtf8("catSubToCat"));

        horizontalLayout_3->addWidget(catSubToCat);


        verticalLayout_8->addWidget(widget_4);

        adminTab->addTab(catModifyTab, QString());

        gridLayout_4->addWidget(adminTab, 0, 0, 1, 1);

        stackedWidget->addWidget(AdminMenu);
        UsrMenu = new QWidget();
        UsrMenu->setObjectName(QString::fromUtf8("UsrMenu"));
        verticalLayout_5 = new QVBoxLayout(UsrMenu);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        widget = new QWidget(UsrMenu);
        widget->setObjectName(QString::fromUtf8("widget"));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        userTab = new QTabWidget(widget);
        userTab->setObjectName(QString::fromUtf8("userTab"));
        userTab->setFont(font2);
        userTab->setIconSize(QSize(16, 16));
        userView = new QWidget();
        userView->setObjectName(QString::fromUtf8("userView"));
        gridLayout_7 = new QGridLayout(userView);
        gridLayout_7->setObjectName(QString::fromUtf8("gridLayout_7"));
        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        label_5 = new QLabel(userView);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        gridLayout_2->addWidget(label_5, 2, 0, 1, 1);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        label_9 = new QLabel(userView);
        label_9->setObjectName(QString::fromUtf8("label_9"));

        verticalLayout_4->addWidget(label_9);

        itemVal = new QSpinBox(userView);
        itemVal->setObjectName(QString::fromUtf8("itemVal"));

        verticalLayout_4->addWidget(itemVal);


        gridLayout_2->addLayout(verticalLayout_4, 6, 0, 1, 1);

        userSubcat = new QComboBox(userView);
        userSubcat->setObjectName(QString::fromUtf8("userSubcat"));

        gridLayout_2->addWidget(userSubcat, 3, 1, 1, 1);

        userCatView = new QPushButton(userView);
        userCatView->setObjectName(QString::fromUtf8("userCatView"));

        gridLayout_2->addWidget(userCatView, 4, 0, 1, 2);

        label_8 = new QLabel(userView);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        gridLayout_2->addWidget(label_8, 3, 0, 1, 1);

        addCart = new QPushButton(userView);
        addCart->setObjectName(QString::fromUtf8("addCart"));

        gridLayout_2->addWidget(addCart, 6, 1, 1, 1);

        userCat = new QComboBox(userView);
        userCat->setObjectName(QString::fromUtf8("userCat"));

        gridLayout_2->addWidget(userCat, 2, 1, 1, 1);

        userViewSale = new QPushButton(userView);
        userViewSale->setObjectName(QString::fromUtf8("userViewSale"));

        gridLayout_2->addWidget(userViewSale, 5, 0, 1, 2);


        gridLayout_7->addLayout(gridLayout_2, 0, 0, 2, 1);

        userTab->addTab(userView, QString());
        userSearch = new QWidget();
        userSearch->setObjectName(QString::fromUtf8("userSearch"));
        verticalLayout_6 = new QVBoxLayout(userSearch);
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        verticalSpacer_6 = new QSpacerItem(20, 120, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout_6->addItem(verticalSpacer_6);

        label_10 = new QLabel(userSearch);
        label_10->setObjectName(QString::fromUtf8("label_10"));

        verticalLayout_6->addWidget(label_10);

        searchLnEdit = new QLineEdit(userSearch);
        searchLnEdit->setObjectName(QString::fromUtf8("searchLnEdit"));

        verticalLayout_6->addWidget(searchLnEdit);

        verticalSpacer_5 = new QSpacerItem(20, 70, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout_6->addItem(verticalSpacer_5);

        searchButton = new QPushButton(userSearch);
        searchButton->setObjectName(QString::fromUtf8("searchButton"));

        verticalLayout_6->addWidget(searchButton);

        verticalSpacer_4 = new QSpacerItem(20, 150, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout_6->addItem(verticalSpacer_4);

        label_11 = new QLabel(userSearch);
        label_11->setObjectName(QString::fromUtf8("label_11"));

        verticalLayout_6->addWidget(label_11);

        verticalSpacer_7 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_6->addItem(verticalSpacer_7);

        userTab->addTab(userSearch, QString());
        userCart = new QWidget();
        userCart->setObjectName(QString::fromUtf8("userCart"));
        gridLayout_8 = new QGridLayout(userCart);
        gridLayout_8->setObjectName(QString::fromUtf8("gridLayout_8"));
        displayCart = new QPushButton(userCart);
        displayCart->setObjectName(QString::fromUtf8("displayCart"));

        gridLayout_8->addWidget(displayCart, 0, 0, 1, 2);

        label_12 = new QLabel(userCart);
        label_12->setObjectName(QString::fromUtf8("label_12"));

        gridLayout_8->addWidget(label_12, 1, 0, 1, 1);

        cartIdLnEdit = new QLineEdit(userCart);
        cartIdLnEdit->setObjectName(QString::fromUtf8("cartIdLnEdit"));

        gridLayout_8->addWidget(cartIdLnEdit, 1, 1, 1, 1);

        label_13 = new QLabel(userCart);
        label_13->setObjectName(QString::fromUtf8("label_13"));

        gridLayout_8->addWidget(label_13, 2, 0, 1, 1);

        cartQuantityLnEdit = new QLineEdit(userCart);
        cartQuantityLnEdit->setObjectName(QString::fromUtf8("cartQuantityLnEdit"));

        gridLayout_8->addWidget(cartQuantityLnEdit, 2, 1, 1, 1);

        cartUpdateButton = new QPushButton(userCart);
        cartUpdateButton->setObjectName(QString::fromUtf8("cartUpdateButton"));

        gridLayout_8->addWidget(cartUpdateButton, 3, 1, 1, 1);

        checkOutButton = new QPushButton(userCart);
        checkOutButton->setObjectName(QString::fromUtf8("checkOutButton"));

        gridLayout_8->addWidget(checkOutButton, 4, 1, 1, 1);

        userTab->addTab(userCart, QString());

        horizontalLayout->addWidget(userTab);

        userTableView = new QTableView(widget);
        userTableView->setObjectName(QString::fromUtf8("userTableView"));

        horizontalLayout->addWidget(userTableView);


        verticalLayout_5->addWidget(widget);

        stackedWidget->addWidget(UsrMenu);

        verticalLayout_7->addWidget(stackedWidget);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1027, 26));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        stackedWidget->setCurrentIndex(2);
        tabWidget->setCurrentIndex(0);
        adminTab->setCurrentIndex(0);
        userTab->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Shopping Application", nullptr));
        pageTitle->setText(QApplication::translate("MainWindow", "Login", nullptr));
        label_6->setText(QApplication::translate("MainWindow", "Enter name:", nullptr));
        label_7->setText(QApplication::translate("MainWindow", "Enter password:", nullptr));
        userLogin_2->setText(QApplication::translate("MainWindow", "login", nullptr));
        userFail->setText(QApplication::translate("MainWindow", "login fail", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(userLogin), QApplication::translate("MainWindow", "User Login", nullptr));
        label_3->setText(QApplication::translate("MainWindow", "Enter name:", nullptr));
        label_4->setText(QApplication::translate("MainWindow", "Enter password:", nullptr));
        adminLogin_2->setText(QApplication::translate("MainWindow", "login", nullptr));
        adminFail->setText(QApplication::translate("MainWindow", "login fail", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(adminLogin), QApplication::translate("MainWindow", "Admin Login", nullptr));
        label->setText(QApplication::translate("MainWindow", "Enter username:", nullptr));
        label_2->setText(QApplication::translate("MainWindow", "Enter password:", nullptr));
        regiConf->setText(QApplication::translate("MainWindow", "register", nullptr));
        regiFail->setText(QApplication::translate("MainWindow", "register fail", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(regi), QApplication::translate("MainWindow", "Register", nullptr));
        guestLogin_2->setText(QApplication::translate("MainWindow", "Continue as Guest", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(guestLogin), QApplication::translate("MainWindow", "Guest", nullptr));
        updateCommit->setText(QApplication::translate("MainWindow", "CommitAll", nullptr));
        updateViewSelect->setItemText(0, QApplication::translate("MainWindow", "Categories", nullptr));
        updateViewSelect->setItemText(1, QApplication::translate("MainWindow", "SubCategories", nullptr));
        updateViewSelect->setItemText(2, QApplication::translate("MainWindow", "Items", nullptr));
        updateViewSelect->setItemText(3, QApplication::translate("MainWindow", "ItemsOnSale", nullptr));

        updateAdd->setText(QApplication::translate("MainWindow", "Add", nullptr));
        updateDelete->setText(QApplication::translate("MainWindow", "Delete Selected", nullptr));
        updateCancel->setText(QApplication::translate("MainWindow", "Cancel", nullptr));
        updateToDiscount->setText(QApplication::translate("MainWindow", "Add Items to Discount", nullptr));
        updateRmExpired->setText(QApplication::translate("MainWindow", "Remove all expired sales items", nullptr));
        adminTab->setTabText(adminTab->indexOf(updateTab), QApplication::translate("MainWindow", "Update", nullptr));
        refresh->setText(QApplication::translate("MainWindow", "Refresh", nullptr));
        catItemToSub->setText(QApplication::translate("MainWindow", "Set Items to Subcategory", nullptr));
        catSubToCat->setText(QApplication::translate("MainWindow", "Set Subcategory to Category", nullptr));
        adminTab->setTabText(adminTab->indexOf(catModifyTab), QApplication::translate("MainWindow", "Category Modify", nullptr));
        label_5->setText(QApplication::translate("MainWindow", "Category:", nullptr));
        label_9->setText(QApplication::translate("MainWindow", "Enter the value:", nullptr));
        userCatView->setText(QApplication::translate("MainWindow", "view", nullptr));
        label_8->setText(QApplication::translate("MainWindow", "SubCategory:", nullptr));
        addCart->setText(QApplication::translate("MainWindow", "add selected item to cart", nullptr));
        userViewSale->setText(QApplication::translate("MainWindow", "view items on sale", nullptr));
        userTab->setTabText(userTab->indexOf(userView), QApplication::translate("MainWindow", "view and add", nullptr));
        label_10->setText(QApplication::translate("MainWindow", "Enter key work for search:", nullptr));
        searchButton->setText(QApplication::translate("MainWindow", "search", nullptr));
        label_11->setText(QApplication::translate("MainWindow", "To add item, please go back to view and add tab.", nullptr));
        userTab->setTabText(userTab->indexOf(userSearch), QApplication::translate("MainWindow", "search", nullptr));
        displayCart->setText(QApplication::translate("MainWindow", "Display your cart", nullptr));
        label_12->setText(QApplication::translate("MainWindow", "Id:", nullptr));
        label_13->setText(QApplication::translate("MainWindow", "Quantity:", nullptr));
        cartUpdateButton->setText(QApplication::translate("MainWindow", "Update", nullptr));
        checkOutButton->setText(QApplication::translate("MainWindow", "Check out", nullptr));
        userTab->setTabText(userTab->indexOf(userCart), QApplication::translate("MainWindow", "cart", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
