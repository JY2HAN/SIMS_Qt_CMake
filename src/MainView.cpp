#include "MainView.h"
#include "ui_MainView.h"

MainView::MainView(QWidget* parent) :
    QWidget(parent),
    ui(new Ui::MainView)
{
    ui->setupUi(this);

    MenuWidget = new Menu;
    AddStuWidget = new Add;
    SearchStuWidget = new Search;
    ModifyStuWidget = new Modify;
    SortStuWidget = new Sort;
    stackLayout = new QStackedLayout;

    stackLayout->addWidget(MenuWidget);
    stackLayout->addWidget(AddStuWidget);
    stackLayout->addWidget(SearchStuWidget);
    stackLayout->addWidget(ModifyStuWidget);
    stackLayout->addWidget(SortStuWidget);

    setLayout(stackLayout);

    connect(MenuWidget, &Menu::display, stackLayout, &QStackedLayout::setCurrentIndex);
    connect(AddStuWidget, &Add::display, stackLayout, &QStackedLayout::setCurrentIndex);
    connect(SearchStuWidget, &Search::display, stackLayout, &QStackedLayout::setCurrentIndex);
    connect(ModifyStuWidget, &Modify::display, stackLayout, &QStackedLayout::setCurrentIndex);
    connect(SortStuWidget, &Sort::display, stackLayout, &QStackedLayout::setCurrentIndex);
}

MainView::~MainView()
{
    delete ui;
}
