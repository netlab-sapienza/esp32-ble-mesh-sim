/*
 * sim_kernel.hpp
 * Kernel for handling simulator calls
 * ie handling a new node, connection loss, message passing
 */

#pragma once
#include "../../management/include/graph.hpp"

namespace espsim {
  struct dev_params_t {
    int dev_id;
  };

  class UniqueIdFunctor {
    unsigned int m_last_id;
    
  public:
    UniqueIdFunctor(unsigned int t_start_id);
    unsigned int operator() { return m_last_id++; }
  };

  typedef void (*dev_fn_t)(void);
  
  class Simulator {
    Graph m_graph;
    UniqueIdFunctor m_id_fnct;
  public:
    Simulator(void): m_graph(), m_id_fnct(0);
    /*
     * Starts a new thread and launch the function t_fn
     */
    int add(dev_fn_t t_fn);
        
  }
}
