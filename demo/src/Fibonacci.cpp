/* generated by rust_qt_binding_generator */
#include "Fibonacci.h"

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
    inline void fibonacciInputChanged(Fibonacci* o)
    {
        emit o->inputChanged();
    }
    inline void fibonacciResultChanged(Fibonacci* o)
    {
        emit o->resultChanged();
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
    Fibonacci::Private* fibonacci_new(Fibonacci*, void (*)(Fibonacci*), void (*)(Fibonacci*));
    void fibonacci_free(Fibonacci::Private*);
    quint32 fibonacci_input_get(const Fibonacci::Private*);
    void fibonacci_input_set(Fibonacci::Private*, uint);
    quint64 fibonacci_result_get(const Fibonacci::Private*);
};
extern "C" {
    quint64 fibonacci_list_data_result(const FibonacciList::Private*, int);
    void fibonacci_list_sort(FibonacciList::Private*, unsigned char column, Qt::SortOrder order = Qt::AscendingOrder);

    int fibonacci_list_row_count(const FibonacciList::Private*);
    bool fibonacci_list_can_fetch_more(const FibonacciList::Private*);
    void fibonacci_list_fetch_more(FibonacciList::Private*);
}
int FibonacciList::columnCount(const QModelIndex &parent) const
{
    return (parent.isValid()) ? 0 : 1;
}

bool FibonacciList::hasChildren(const QModelIndex &parent) const
{
    return rowCount(parent) > 0;
}

int FibonacciList::rowCount(const QModelIndex &parent) const
{
    return (parent.isValid()) ? 0 : fibonacci_list_row_count(m_d);
}

QModelIndex FibonacciList::index(int row, int column, const QModelIndex &parent) const
{
    if (!parent.isValid() && row >= 0 && row < rowCount(parent) && column >= 0 && column < 1) {
        return createIndex(row, column, (quintptr)0);
    }
    return QModelIndex();
}

QModelIndex FibonacciList::parent(const QModelIndex &) const
{
    return QModelIndex();
}

bool FibonacciList::canFetchMore(const QModelIndex &parent) const
{
    return (parent.isValid()) ? 0 : fibonacci_list_can_fetch_more(m_d);
}

void FibonacciList::fetchMore(const QModelIndex &parent)
{
    if (!parent.isValid()) {
        fibonacci_list_fetch_more(m_d);
    }
}

void FibonacciList::sort(int column, Qt::SortOrder order)
{
    fibonacci_list_sort(m_d, column, order);
}
Qt::ItemFlags FibonacciList::flags(const QModelIndex &i) const
{
    auto flags = QAbstractItemModel::flags(i);
    return flags;
}
QVariant FibonacciList::data(const QModelIndex &index, int role) const
{
    QVariant v;
    Q_ASSERT(rowCount(index.parent()) > index.row());
    QString s;
    QByteArray b;
    switch (index.column()) {
    case 0:
        switch (role) {
        case Qt::DisplayRole:
        case Qt::UserRole + 0:
            v = fibonacci_list_data_result(m_d, index.row());
            break;
        }
        break;
    }
    return v;
}
QHash<int, QByteArray> FibonacciList::roleNames() const {
    QHash<int, QByteArray> names = QAbstractItemModel::roleNames();
    names.insert(Qt::UserRole + 0, "result");
    return names;
}
bool FibonacciList::setData(const QModelIndex &index, const QVariant &value, int role)
{
    bool set = false;
    if (set) {
        emit dataChanged(index, index, QVector<int>() << role);
    }
    return set;
}
extern "C" {
    FibonacciList::Private* fibonacci_list_new(FibonacciList*,
        void (*)(const FibonacciList*),
        void (*)(FibonacciList*),
        void (*)(FibonacciList*),
        void (*)(FibonacciList*, int, int),
        void (*)(FibonacciList*),
        void (*)(FibonacciList*, int, int),
        void (*)(FibonacciList*));
    void fibonacci_list_free(FibonacciList::Private*);
};
Fibonacci::Fibonacci(bool /*owned*/, QObject *parent):
    QObject(parent),
    m_d(0),
    m_ownsPrivate(false) {}
Fibonacci::Fibonacci(QObject *parent):
    QObject(parent),
    m_d(fibonacci_new(this,
        fibonacciInputChanged,
        fibonacciResultChanged)),
    m_ownsPrivate(true) {
}

Fibonacci::~Fibonacci() {
    if (m_ownsPrivate) {
        fibonacci_free(m_d);
    }
}
quint32 Fibonacci::input() const
{
    return fibonacci_input_get(m_d);
}
void Fibonacci::setInput(uint v) {
    fibonacci_input_set(m_d, v);
}
quint64 Fibonacci::result() const
{
    return fibonacci_result_get(m_d);
}
FibonacciList::FibonacciList(bool /*owned*/, QObject *parent):
    QAbstractItemModel(parent),
    m_d(0),
    m_ownsPrivate(false) {}
FibonacciList::FibonacciList(QObject *parent):
    QAbstractItemModel(parent),
    m_d(fibonacci_list_new(this,
        [](const FibonacciList* o) {
            emit o->newDataReady(QModelIndex());
        },
        [](FibonacciList* o) {
            o->beginResetModel();
        },
        [](FibonacciList* o) {
            o->endResetModel();
        },
        [](FibonacciList* o, int first, int last) {
            o->beginInsertRows(QModelIndex(), first, last);
        },
        [](FibonacciList* o) {
            o->endInsertRows();
        },
        [](FibonacciList* o, int first, int last) {
            o->beginRemoveRows(QModelIndex(), first, last);
        },
        [](FibonacciList* o) {
            o->endRemoveRows();
        }
)),
    m_ownsPrivate(true) {
    connect(this, &FibonacciList::newDataReady, this, [this](const QModelIndex& i) {
        fetchMore(i);
    }, Qt::QueuedConnection);
}

FibonacciList::~FibonacciList() {
    if (m_ownsPrivate) {
        fibonacci_list_free(m_d);
    }
}
