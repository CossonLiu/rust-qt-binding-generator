/* generated by rust_qt_binding_generator */
#include "test_object_rust.h"

namespace {
    template <typename T>
    struct option {
    public:
        T value;
        bool some;
        operator QVariant() const {
            if (some) {
                return QVariant(value);
            }
            return QVariant();
        }
    };
    struct qbytearray_t {
    private:
        const char* data;
        int len;
    public:
        qbytearray_t(const QByteArray& v):
            data(v.data()),
            len(v.size()) {
        }
        operator QByteArray() const {
            return QByteArray(data, len);
        }
    };
    struct qstring_t {
    private:
        const void* data;
        int len;
    public:
        qstring_t(const QString& v):
            data(static_cast<const void*>(v.utf16())),
            len(v.size()) {
        }
        operator QString() const {
            return QString::fromUtf8(static_cast<const char*>(data), len);
        }
    };
    struct qmodelindex_t {
        int row;
        quintptr id;
    };
    inline void personUserNameChanged(Person* o)
    {
        emit o->userNameChanged();
    }

}
typedef void (*qstring_set)(QString*, qstring_t*);
void set_qstring(QString* v, qstring_t* val) {
    *v = *val;
}
typedef void (*qbytearray_set)(QByteArray*, qbytearray_t*);
void set_qbytearray(QByteArray* v, qbytearray_t* val) {
    *v = *val;
}
extern "C" {
    Person::Private* person_new(Person*, void (*)(Person*));
    void person_free(Person::Private*);
    void person_user_name_get(const Person::Private*, QString*, qstring_set);
    void person_user_name_set(Person::Private*, qstring_t);
};
Person::Person(bool /*owned*/, QObject *parent):
    QObject(parent),
    m_d(0),
    m_ownsPrivate(false) {}
Person::Person(QObject *parent):
    QObject(parent),
    m_d(person_new(this,
        personUserNameChanged)),
    m_ownsPrivate(true) {
}

Person::~Person() {
    if (m_ownsPrivate) {
        person_free(m_d);
    }
}
QString Person::userName() const
{
    QString v;
    person_user_name_get(m_d, &v, set_qstring);
    return v;
}
void Person::setUserName(const QString& v) {
    person_user_name_set(m_d, v);
}
