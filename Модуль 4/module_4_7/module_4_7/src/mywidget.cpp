// mywidget.cpp
#include <QApplication.h>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QComboBox>
#include <QPushButton>
#include <QTextEdit>
#include <QMenuBar> //В линейку, QMenu - пурап-меню
// === Меню "Файл" ===
//QMenu *fileMenu = menuBar()->addMenu("📁 Файл");
// Пункты меню:
//fileMenu->addAction("📂 Открыть", this, &myWidget::onOpen);
#include <QFileDialog>
#include "mywidget.h"
#include "everydaydishes.h"
#include "jsonexporter.h"
#include "wordexporter.h"


myWidget::myWidget(QWidget *parent)
    : QMainWindow(parent),
      btnPrint(nullptr),  // ← Инициализируем поле класса нулем
      editForm(nullptr),
      sysmenu(nullptr),
      dishes(nullptr)
{
    //Указатель на логику
    dishes = new everydayDishes();

    // Вызываем методы инициализации ПО ПОРЯДКУ:
    setupWindow();      // 1. Сначала настройки самого окна
    createWidgets();    // 2. Потом создаём виджеты (иначе нечего расставлять)
    setupLayouts();     // 3. Расставляем виджеты по местам
    setupConnections(); // 4. В конце подключаем сигналы (иначе нечего подключать)
}

myWidget::~myWidget()
{
    delete dishes;
}

//В файле .срр типы функций класса проставляются так же как и в хеддере

void myWidget::setupWindow()
{
    // Локальные константы — видны только внутри этой функции
    // Можно было с  #define SIZE 600, главное помнить что в  #define SIZE 600 не ставится ;
    //
    constexpr int MIN_SIZE_X = 300; // Значение известно на этапе компиляции и никогда не изменится
    constexpr int MIN_SIZE_Y = 500;
    constexpr int SIZE_X = 600;
    constexpr int SIZE_Y = 600;

    resize(SIZE_X, SIZE_Y);                  // начальный размер changed form
    setMinimumSize(MIN_SIZE_X, MIN_SIZE_Y);  // минимальный размер

    // Создаём центральный виджет
    QWidget *centralWidget = new QWidget(this);
    setCentralWidget(centralWidget);
}

void myWidget::createWidgets()
{
    // 1. Массив с днями недели (локальная константа)
    constexpr const char* weekDays[7] = {
        "Понедельник", "Вторник", "Среда",
        "Четверг", "Пятница", "Суббота", "Воскресенье"
    };

    // 2. Создаём ComboBox
    // centralWidget() — родитель: виджет удалится вместе с окном
   // daySelector = new QComboBox(centralWidget());

    // 3. Заполняем циклом
    // i = 0 → Monday, i = 1 → Tuesday, и так далее
   /* for (int i = 0; i < 7; ++i) {
        daySelector->addItem(weekDays[i]);
    }*/

    // Создаём кнопки
    // "Вывести на экран" — текст на кнопке
    // centralWidget() — родитель для корректного удаления
    btnPrint = new QPushButton("Вывести на экран", centralWidget());

    // Text Edit Form
    // QTextEdit — многострочное поле для вывода меню
    // centralWidget() — родитель
    editForm = new QTextEdit(centralWidget());

    //Menu system
    sysmenu = new QMenuBar(centralWidget());

    // Запрещаем пользователю редактировать меню (только чтение)
    editForm->setReadOnly(true);
    QMenuBar *menuBar = this->menuBar();

    // Меню "Файл"
    QMenu *fileMenu = menuBar->addMenu("📁 Файл");

    // Создаём действия, но НЕ подключаем их здесь!
    // Сохраняем как поля класса, если нужно подключить потом
    actionSaveJson = fileMenu->addAction("💾 Сохранить в JSON");
    actionSaveWord = fileMenu->addAction("📄 Сохранить в Word");

    fileMenu->addSeparator();
    actionExit = fileMenu->addAction("🚪 Выход");

    // Меню "Справка"
    QMenu *helpMenu = menuBar->addMenu("❓ Справка");
    actionAbout = helpMenu->addAction("ℹ️ О программе");
}

void myWidget::setupLayouts()
{
    // 1. ГЛАВНЫЙ: Горизонтальный (делит на ЛЕВО и ПРАВО)
    auto *mainLayout = new QHBoxLayout(centralWidget());

    // 2. ЛЕВАЯ КОЛОНКА: Вертикальная (ComboBox НАД кнопкой, ПО ЦЕНТРУ)
    auto *leftLayout = new QVBoxLayout();

    // ✅ НОВАЯ СТРОКА: Пружина СВЕРХУ (толкает виджеты ВНИЗ) ⬇️
    leftLayout->addStretch();

   // leftLayout->addWidget(daySelector);   // 1. ComboBox
    leftLayout->addWidget(btnPrint);      // 2. Кнопка под ним
    leftLayout->setSpacing(10);           // Отступ между элементами

    // ✅ Пружина СНИЗУ (толкает виджеты ВВЕРХ) ⬆️
    leftLayout->addStretch();

    // 3. ПРАВАЯ КОЛОНКА: Вертикальная (TextEdit)
    auto *rightLayout = new QVBoxLayout();
    rightLayout->addWidget(editForm);     // TextEdit занимает всё место

    // 4. СОБИРАЕМ: Левую и Правую колонки в Главный
    mainLayout->addLayout(leftLayout);    // ← LEFT (ComboBox + Button)
    mainLayout->addLayout(rightLayout);   // ← RIGHT (TextEdit)

    // 5. Отступы от краёв окна
    mainLayout->setContentsMargins(15, 15, 15, 15);
}

void myWidget::setupConnections()
{
    // === 1. Подключаем выбор дня недели к обновлению меню ===
    // Сигнал: currentIndexChanged(int) — срабатывает, когда пользователь меняет элемент
    // Слот: updateMenu(int) — наш метод, который мы напишем чуть ниже
    /*connect(daySelector,
            QOverload<int>::of(&QComboBox::currentIndexChanged),
            this,
            &myWidget::updateMenu);*/

    // === 2. Подключаем кнопку "Вывести на экран" ===
    connect(btnPrint,
            &QPushButton::clicked,
            this,
            &myWidget::onPrintClicked);

    // === 3. класс everydayDishes в слот/сигнал не учавствует это чистая логика на С++
    connect(actionExit, &QAction::triggered, this, &myWidget::exitApp);
    connect(actionSaveJson, &QAction::triggered, this, &myWidget::saveToJson);
    connect(actionSaveWord, &QAction::triggered, this, &myWidget::saveToWord);
}

void myWidget::onPrintClicked()
{
    // 1. Получаем меню (логика сама узнаёт день)
    const std::string* menu = dishes->getMenu();

    // 2. Формируем вывод
    QString output = "<h3>🍽️ Меню на сегодня</h3><hr><br>";
    for (int i = 0; i < 4; ++i) {
        output += QString::number(i+1) + ". "
                  + QString::fromStdString(menu[i])
                  + "<br>";
    }

    // 3. Показываем на экране
    editForm->setHtml(output);
}

// =================================================================
// СЛОТ: Сохранить в JSON
// =================================================================
void myWidget::saveToJson()
{
    qDebug() << "[INFO] saveToJson() started";

    // 1. Получаем меню из логики
    const std::string* menu = dishes->getMenu();
    if (!menu) {
        qWarning() << "[WARN] menu is null!";
        return;
    }

    // 2. Спрашиваем путь у пользователя (ЛЮБАЯ папка!)
    QString filePath = QFileDialog::getSaveFileName(
        this, "Сохранить в JSON", "", "JSON Files (*.json)"
    );

    if (filePath.isEmpty()) {
        qDebug() << "[INFO] User cancelled save dialog";
        return;  // Пользователь нажал «Отмена»
    }

    qDebug() << "[INFO] Saving to:" << filePath;

    // 3. Экспортируем
    JsonExporter exporter;
    if (exporter.exportMenu(menu, "Сегодня", filePath)) {
        qDebug() << "[INFO] JSON saved successfully!";
    } else {
        qCritical() << "[ERROR] Failed to save JSON file!";
    }
}

// =================================================================
// СЛОТ: Сохранить в Word
// =================================================================
void myWidget::saveToWord()
{
    qDebug() << "[INFO] saveToWord() started";

    // 1. Получаем меню из логики
    const std::string* menu = dishes->getMenu();
    if (!menu) {
        qWarning() << "[WARN] menu is null!";
        return;
    }

    // 2. Спрашиваем путь у пользователя (ЛЮБАЯ папка!)
    QString filePath = QFileDialog::getSaveFileName(
        this, "Сохранить в Word", "", "Word Files (*.docx)"
    );

    if (filePath.isEmpty()) {
        qDebug() << "[INFO] User cancelled save dialog";
        return;
    }

    qDebug() << "[INFO] Saving to:" << filePath;

    // 3. Экспортируем
    WordExporter exporter;
    if (exporter.exportMenu(menu, "Сегодня", filePath)) {
        qDebug() << "[INFO] Word saved successfully!";
    } else {
        qCritical() << "[ERROR] Failed to save Word file!";
    }
}

// =================================================================
// СЛОТ: Выход
// =================================================================
void myWidget::exitApp()
{
    qDebug() << "[INFO] Application exiting...";
    QApplication::quit();
}
