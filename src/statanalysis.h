/*
This file is part of Fast Track.

    FastTrack is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    FastTrack is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with FastTrack.  If not, see <https://www.gnu.org/licenses/>.
*/

#ifndef STATANALYSIS_H
#define STATANALYSIS_H

#include <QAction>
#include <QBarCategoryAxis>
#include <QBoxPlotSeries>
#include <QBoxSet>
#include <QChart>
#include <QChartView>
#include <QCheckBox>
#include <QDir>
#include <QFileDialog>
#include <QFileInfo>
#include <QHash>
#include <QHashIterator>
#include <QIcon>
#include <QInputDialog>
#include <QLineSeries>
#include <QList>
#include <QMainWindow>
#include <QObject>
#include <QPixmap>
#include <QSettings>
#include <QString>
#include <QTableWidgetItem>
#include <QValueAxis>
#include <algorithm>
#include <cmath>
#include <functional>

#include "data.h"

namespace Ui {
class StatAnalysis;
}

class StatAnalysis : public QMainWindow {
  Q_OBJECT

 public:
  explicit StatAnalysis(QWidget *parent = nullptr, bool isStandalone = true);
  StatAnalysis(const StatAnalysis &T) = delete;
  StatAnalysis &operator=(const StatAnalysis &T) = delete;
  StatAnalysis &operator=(StatAnalysis &&T) = delete;
  StatAnalysis(StatAnalysis &&T) = delete;
  ~StatAnalysis();
  void openTrackingData(const QString &file, bool loadOnDemand = false);
  void openTrackingData(Data *data, bool loadOnDemand = false);
  void reload();
  void clear();

 private slots:
  void openTrackingData();
  void loadObjectList();
  void refresh();
  void initPlots(const QList<int> &objects);
  void refreshPlots(const QList<int> &objects);
  void clearPlots();
  QList<int> getSelectedObjects();
  double median(int begin, int end, const QList<double> &sortedList);

 private:
  Ui::StatAnalysis *ui;
  bool isStandalone;
  Data *trackingData;
  QVector<QChart *> plots;
  QSettings *settingsFile;
  QString memoryDir;
  double ruler;
  double timeScale;
  bool isData;
  QLabel *scale;
};

#endif  // STATANALYSIS_H