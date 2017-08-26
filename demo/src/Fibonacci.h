/* generated by rust_qt_binding_generator */
#ifndef FIBONACCI_H
#define FIBONACCI_H

#include <QObject>
#include <QAbstractItemModel>

class Fibonacci : public QObject
{
    Q_OBJECT
public:
    class Private;
private:
    Private * m_d;
    bool m_ownsPrivate;
    Q_PROPERTY(quint32 input READ input WRITE setInput NOTIFY inputChanged FINAL)
    Q_PROPERTY(quint64 result READ result NOTIFY resultChanged FINAL)
    explicit Fibonacci(bool owned, QObject *parent);
public:
    explicit Fibonacci(QObject *parent = nullptr);
    ~Fibonacci();
    quint32 input() const;
    void setInput(uint v);
    quint64 result() const;
signals:
    void inputChanged();
    void resultChanged();
};

class FibonacciList : public QAbstractItemModel
{
    Q_OBJECT
public:
    class Private;
private:
    Private * m_d;
    bool m_ownsPrivate;
    explicit FibonacciList(bool owned, QObject *parent);
public:
    explicit FibonacciList(QObject *parent = nullptr);
    ~FibonacciList();

    int columnCount(const QModelIndex &parent = QModelIndex()) const override;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
    bool setData(const QModelIndex &index, const QVariant &value, int role = Qt::EditRole) override;
    QModelIndex index(int row, int column, const QModelIndex &parent = QModelIndex()) const override;
    QModelIndex parent(const QModelIndex &index) const override;
    bool hasChildren(const QModelIndex &parent = QModelIndex()) const override;
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    bool canFetchMore(const QModelIndex &parent) const override;
    void fetchMore(const QModelIndex &parent) override;
    Qt::ItemFlags flags(const QModelIndex &index) const override;
    void sort(int column, Qt::SortOrder order = Qt::AscendingOrder) override;
    QHash<int, QByteArray> roleNames() const override;
signals:
    // new data is ready to be made available to the model with fetchMore()
    void newDataReady(const QModelIndex &parent) const;
signals:
};
#endif // FIBONACCI_H
