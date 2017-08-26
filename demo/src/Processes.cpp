/* generated by rust_qt_binding_generator */
#include "Processes.h"

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
    void processes_data_cmd(const Processes::Private*, quintptr, QString*, qstring_set);
    quint8 processes_data_cpu_percentage(const Processes::Private*, quintptr);
    float processes_data_cpu_usage(const Processes::Private*, quintptr);
    quint64 processes_data_memory(const Processes::Private*, quintptr);
    void processes_data_name(const Processes::Private*, quintptr, QString*, qstring_set);
    uint processes_data_pid(const Processes::Private*, quintptr);
    uint processes_data_uid(const Processes::Private*, quintptr);
    void processes_sort(Processes::Private*, unsigned char column, Qt::SortOrder order = Qt::AscendingOrder);

    int processes_row_count(const Processes::Private*, quintptr, bool);
    bool processes_can_fetch_more(const Processes::Private*, quintptr, bool);
    void processes_fetch_more(Processes::Private*, quintptr, bool);
    quintptr processes_index(const Processes::Private*, quintptr, bool, int);
    qmodelindex_t processes_parent(const Processes::Private*, quintptr);
    int processes_row(const Processes::Private*, quintptr);
}
int Processes::columnCount(const QModelIndex &) const
{
    return 3;
}

bool Processes::hasChildren(const QModelIndex &parent) const
{
    return rowCount(parent) > 0;
}

int Processes::rowCount(const QModelIndex &parent) const
{
    if (parent.isValid() && parent.column() != 0) {
        return 0;
    }
    return processes_row_count(m_d, parent.internalId(), parent.isValid());
}

QModelIndex Processes::index(int row, int column, const QModelIndex &parent) const
{
    if (row < 0 || column < 0 || column >= 3) {
        return QModelIndex();
    }
    if (parent.isValid() && parent.column() != 0) {
        return QModelIndex();
    }
    if (row >= rowCount(parent)) {
        return QModelIndex();
    }
    const quintptr id = processes_index(m_d, parent.internalId(), parent.isValid(), row);
    return createIndex(row, column, id);
}

QModelIndex Processes::parent(const QModelIndex &index) const
{
    if (!index.isValid()) {
        return QModelIndex();
    }
    const qmodelindex_t parent = processes_parent(m_d, index.internalId());
    return parent.row >= 0 ?createIndex(parent.row, 0, parent.id) :QModelIndex();
}

bool Processes::canFetchMore(const QModelIndex &parent) const
{
    if (parent.isValid() && parent.column() != 0) {
        return false;
    }
    return processes_can_fetch_more(m_d, parent.internalId(), parent.isValid());
}

void Processes::fetchMore(const QModelIndex &parent)
{
    processes_fetch_more(m_d, parent.internalId(), parent.isValid());
}

void Processes::sort(int column, Qt::SortOrder order)
{
    processes_sort(m_d, column, order);
}
Qt::ItemFlags Processes::flags(const QModelIndex &i) const
{
    auto flags = QAbstractItemModel::flags(i);
    return flags;
}
QVariant Processes::data(const QModelIndex &index, int role) const
{
    QVariant v;
    Q_ASSERT(rowCount(index.parent()) > index.row());
    QString s;
    QByteArray b;
    switch (index.column()) {
    case 0:
        switch (role) {
        case Qt::UserRole + 0:
            processes_data_cmd(m_d, index.internalId(), &s, set_qstring);
            if (!s.isNull()) v.setValue<QString>(s);
            break;
        case Qt::UserRole + 1:
            v = processes_data_cpu_percentage(m_d, index.internalId());
            break;
        case Qt::UserRole + 2:
            v = processes_data_cpu_usage(m_d, index.internalId());
            break;
        case Qt::UserRole + 3:
            v = processes_data_memory(m_d, index.internalId());
            break;
        case Qt::DisplayRole:
        case Qt::UserRole + 4:
            processes_data_name(m_d, index.internalId(), &s, set_qstring);
            if (!s.isNull()) v.setValue<QString>(s);
            break;
        case Qt::ToolTipRole:
        case Qt::UserRole + 5:
            v = processes_data_pid(m_d, index.internalId());
            break;
        case Qt::UserRole + 6:
            v = processes_data_uid(m_d, index.internalId());
            break;
        }
        break;
    case 1:
        switch (role) {
        case Qt::DisplayRole:
        case Qt::UserRole + 2:
            v = processes_data_cpu_usage(m_d, index.internalId());
            break;
        }
        break;
    case 2:
        switch (role) {
        case Qt::DisplayRole:
        case Qt::UserRole + 3:
            v = processes_data_memory(m_d, index.internalId());
            break;
        }
        break;
    }
    return v;
}
QHash<int, QByteArray> Processes::roleNames() const {
    QHash<int, QByteArray> names = QAbstractItemModel::roleNames();
    names.insert(Qt::UserRole + 0, "cmd");
    names.insert(Qt::UserRole + 1, "cpuPercentage");
    names.insert(Qt::UserRole + 2, "cpuUsage");
    names.insert(Qt::UserRole + 3, "memory");
    names.insert(Qt::UserRole + 4, "name");
    names.insert(Qt::UserRole + 5, "pid");
    names.insert(Qt::UserRole + 6, "uid");
    return names;
}
bool Processes::setData(const QModelIndex &index, const QVariant &value, int role)
{
    bool set = false;
    if (set) {
        emit dataChanged(index, index, QVector<int>() << role);
    }
    return set;
}
extern "C" {
    Processes::Private* processes_new(Processes*,
        void (*)(const Processes*, quintptr, bool),
        void (*)(Processes*),
        void (*)(Processes*),
        void (*)(Processes*, option<quintptr>, int, int),
        void (*)(Processes*),
        void (*)(Processes*, option<quintptr>, int, int),
        void (*)(Processes*));
    void processes_free(Processes::Private*);
};
Processes::Processes(bool /*owned*/, QObject *parent):
    QAbstractItemModel(parent),
    m_d(0),
    m_ownsPrivate(false) {}
Processes::Processes(QObject *parent):
    QAbstractItemModel(parent),
    m_d(processes_new(this,
        [](const Processes* o, quintptr id, bool valid) {
            if (valid) {
                int row = processes_row(o->m_d, id);
                emit o->newDataReady(o->createIndex(row, 0, id));
            } else {
                emit o->newDataReady(QModelIndex());
            }
        },
        [](Processes* o) {
            o->beginResetModel();
        },
        [](Processes* o) {
            o->endResetModel();
        },
        [](Processes* o, option<quintptr> id, int first, int last) {
            if (id.some) {
                int row = processes_row(o->m_d, id.value);
                o->beginInsertRows(o->createIndex(row, 0, id.value), first, last);
            } else {
                o->beginInsertRows(QModelIndex(), first, last);
            }
        },
        [](Processes* o) {
            o->endInsertRows();
        },
        [](Processes* o, option<quintptr> id, int first, int last) {
            if (id.some) {
                int row = processes_row(o->m_d, id.value);
                o->beginRemoveRows(o->createIndex(row, 0, id.value), first, last);
            } else {
                o->beginRemoveRows(QModelIndex(), first, last);
            }
        },
        [](Processes* o) {
            o->endRemoveRows();
        }
)),
    m_ownsPrivate(true) {
    connect(this, &Processes::newDataReady, this, [this](const QModelIndex& i) {
        fetchMore(i);
    }, Qt::QueuedConnection);
}

Processes::~Processes() {
    if (m_ownsPrivate) {
        processes_free(m_d);
    }
}
