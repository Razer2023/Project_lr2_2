#include <iostream>
#include <string>
using namespace std;

class sales {
protected:
    float sales_data[3];
public:
    void get_sales_data() {
        cout << "Введите общую стоимость проданных книг за последние 3 месяца:\n";
        for (int i = 0; i < 3; i++) {
            cout << "Месяц " << (i + 1) << ": ";
            cin >> sales_data[i];
        }
    }

    void put_sales_data() const {
        cout << "Данные о продажах за последние 3 месяца:\n";
        for (int i = 0; i < 3; i++) {
            cout << "Месяц " << (i + 1) << ": " << sales_data[i] << endl;
        }
    }
};

class publication {
protected:
    string title;
    float price;
public:
    void get_data() {
        cout << "Введите название: ";
        cin.ignore();
        getline(cin, title);
        cout << "Введите цену: ";
        cin >> price;
    }

    void put_data() const {
        cout << "Название: " << title << endl;
        cout << "Цена: " << price << endl;
    }
};

class book : public publication, public sales {
private:
    int page_count;
public:
    void get_data() {
        publication::get_data();
        cout << "Введите количество страниц: ";
        cin >> page_count;
        sales::get_sales_data();
    }

    void put_data() const {
        publication::put_data();
        cout << "Количество страниц: " << page_count << endl;
        sales::put_sales_data();
    }
};

class type : public publication, public sales {
private:
    float playing_time;
public:
    void get_data() {
        publication::get_data();
        cout << "Введите время воспроизведения (в минутах): ";
        cin >> playing_time;
        sales::get_sales_data();
    }

    void put_data() const {
        publication::put_data();
        cout << "Время воспроизведения: " << playing_time << " минут" << endl;
        sales::put_sales_data();
    }
};

int main() {
    book my_book;
    type my_type;

    cout << "Ввод данных для книги\n";
    my_book.get_data();

    cout << "\nВвод данных для аудиозаписи\n";
    my_type.get_data();

    cout << "\nВывод данных для книги\n";
    my_book.put_data();

    cout << "\nВывод данных для аудиозаписи\n";
    my_type.put_data();

    return 0;
}
