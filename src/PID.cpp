#include "PID.h"

/**
 * TODO: Complete the PID class. You may add any additional desired functions.
 */

PID::PID() {}

PID::~PID() {}

void PID::Init(double Kp_, double Ki_, double Kd_) {
  /**
   * TODO: Initialize PID coefficients (and errors, if needed)
   */
  this->Kp = Kp_;
  this->Ki = Ki_;
  this->Kd = Kd_;
  this->p_error = 0.0;
  this->i_error = 0.0;
  this->d_error = 0.0;

}

void PID::UpdateError(double cte) {
  /**
   * TODO: Update PID errors based on cte.
   */
  d_error = cte - p_error;

  i_error += cte;

  p_error = cte;

}

double PID::TotalError() {
  /**
   * TODO: Calculate and return the total error
   */
  double tot_error = - (Kp * p_error + Ki * i_error + Kd * d_error);
  
  return tot_error;
//   return 0.0;  // TODO: Add your total error calc here!
}