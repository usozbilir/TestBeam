#ifndef HGCAL_TB_DETECTOR_LAYOUT_H
#define HGCAL_TB_DETECTOR_LAYOUT_H

#include <HGCal/DataFormats/interface/HGCalTBModule.h>
#include <HGCal/DataFormats/interface/HGCalTBLayer.h>
#include <iostream>
#include <set>
#include <algorithm>

class HGCalTBDetectorLayout{
 public:
  HGCalTBDetectorLayout(){;}
  ~HGCalTBDetectorLayout(){;}
    
  void add( HGCalTBLayer layer ){ _layers.push_back(layer); }
  HGCalTBLayer at(int i){ return _layers.at(i); }
  std::vector<HGCalTBLayer>& layers(){return _layers;}
  int nlayers(){
    std::set<int> l;
    for( auto il : _layers )
      l.insert(il.layerID());
    return l.size();
  }
  bool layerExists( HGCalTBLayer layer )
  {
    if( std::find(_layers.begin(), _layers.end(), layer)!=_layers.end() )
      return true;
    else return false;
  }
 private:
  std::vector<HGCalTBLayer> _layers;
};

#endif