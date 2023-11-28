#include <QApplication>
#include <QWidget>
#include <QVBoxLayout>
#include <QLineEdit>
#include <QPushButton>
#include <QMessageBox>

class TextTransferApp : public QWidget {
    Q_OBJECT

public:
    TextTransferApp(QWidget *parent = nullptr) : QWidget(parent) {
        // Введення текстової інформації
        inputField = new QLineEdit(this);

        // Виведення текстової інформації
        outputField = new QLineEdit(this);
        outputField->setReadOnly(true);

        // Кнопка для передачі тексту
        transferButton = new QPushButton("Передати текст", this);
        connect(transferButton, SIGNAL(clicked()), this, SLOT(transferText()));

        // Кнопка для завершення програми
        exitButton = new QPushButton("Завершити", this);
        connect(exitButton, SIGNAL(clicked()), this, SLOT(close()));

        // Розміщення елементів вікна
        QVBoxLayout *layout = new QVBoxLayout(this);
        layout->addWidget(inputField);
        layout->addWidget(outputField);
        layout->addWidget(transferButton);
        layout->addWidget(exitButton);

        setLayout(layout);
    }

private slots:
    void transferText() {
        // Отримання тексту з введеного поля
        QString text = inputField->text();

        // Виведення тексту у виведеному полі
        outputField->setText(text);
    }

private:
    QLineEdit *inputField;
    QLineEdit *outputField;
    QPushButton *transferButton;
    QPushButton *exitButton;
};

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    TextTransferApp window;
    window.setWindowTitle("Text Transfer App");
    window.setGeometry(100, 100, 400, 200);
    window.show();

    return app.exec();
}

#include "main.moc"
