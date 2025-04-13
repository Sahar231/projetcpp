#ifndef PYTHONWORKER_H
#define PYTHONWORKER_H

#include <QThread>
#include <QProcess>

class PythonWorker : public QThread {
    Q_OBJECT
public:
    QString equipmentName;
    QString output;

    void run() override {
        QProcess process;
        QString program = "python";
        QStringList arguments;
        arguments << "C:/Users/Sahar/Bureau/project/interfce/ai auto fill/generation.py"  << equipmentName;

        process.start(program, arguments);
        if (!process.waitForStarted()) {
            output = "Erreur de démarrage Python!";
            return;
        }

        if (!process.waitForFinished()) {
            output = "Erreur d'exécution: " + process.errorString();
            return;
        }

        output = process.readAllStandardOutput().trimmed();
    }
};

#endif // PYTHONWORKER_H

