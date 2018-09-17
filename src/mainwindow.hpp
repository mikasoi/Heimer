// This file is part of Heimer.
// Copyright (C) 2018 Jussi Lind <jussi.lind@iki.fi>
//
// Heimer is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
// Heimer is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with Heimer. If not, see <http://www.gnu.org/licenses/>.

#ifndef MAINWINDOW_HPP
#define MAINWINDOW_HPP

#include <QMainWindow>
#include <QCloseEvent>
#include <QGraphicsScene>
#include <QString>

#include "statemachine.hpp"

#include <memory>

class AboutDlg;
class EditorData;
class EditorView;
class QAction;
class QCheckBox;
class QSlider;
class QTextEdit;
class Mediator;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:

    MainWindow();

    ~MainWindow();

    static MainWindow * instance();

    void console(QString text);

    void disableUndoAndRedo();

    void initialize();

    void initializeNewMindMap();

    void saveWindowSize();

    void setMediator(std::shared_ptr<Mediator> mediator);

    void setSaveActionStatesOnNewMindMap();

    void setSaveActionStatesOnOpenedMindMap();

    void setTitle();

public slots:

    void enableUndo(bool enable);

    void enableSave(bool enable);

    void enableSaveAs(bool enable);

    void showErrorDialog(QString message);

protected:

    void closeEvent(QCloseEvent * event) override;

signals:

    void actionTriggered(StateMachine::Action action);

    void zoomInTriggered();

    void zoomOutTriggered();

    void zoomToFitTriggered();

private slots:

    void setupMindMapAfterUndoOrRedo();

    void showAboutDlg();

    void showAboutQtDlg();

private:

    void addRedoAction(QMenu & menu);

    void addUndoAction(QMenu & menu);

    void createEditMenu();

    void createFileMenu();

    void createHelpMenu();

    void createViewMenu();

    void populateMenuBar();

    AboutDlg * m_aboutDlg;

    QAction * m_saveAction = nullptr;

    QAction * m_saveAsAction = nullptr;

    QAction * m_undoAction = nullptr;

    QAction * m_redoAction = nullptr;

    QString m_argMindMapFile;

    std::shared_ptr<Mediator> m_mediator;

    const char * m_settingsGroup = "MainWindow";

    bool m_closeNow = false;

    static MainWindow * m_instance;
};

#endif // MAINWINDOW_HPP

