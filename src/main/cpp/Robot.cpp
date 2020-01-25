/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include <frc/smartdashboard/SmartDashboard.h>
#include <cameraserver/CameraServer.h>
#include <iostream>

#include "Robot.h"

#include "StarDust/control/BetterController.hpp"

void Robot::RobotInit() {
    frc::CameraServer::GetInstance()->StartAutomaticCapture(0);
    frc::CameraServer::GetInstance()->StartAutomaticCapture(1);
}

void Robot::RobotPeriodic() {
    starDustRobot.RobotPeriodic();
}

void Robot::AutonomousInit() {
    starDustRobot.AutonomousInit();
}

void Robot::AutonomousPeriodic() {
    starDustRobot.AutonomousPeriodic();
}

void Robot::TeleopInit() {
    starDustRobot.TeleopInit();
}

void Robot::TeleopPeriodic() {
    starDustRobot.TeleopPeriodic();

    drivetrain.drive(&xboxController);
}

void Robot::TestPeriodic() {
    starDustRobot.TestPeriodic();
}

void Robot::DisabledInit() {}

#ifndef RUNNING_FRC_TESTS
int main() { return frc::StartRobot<Robot>(); }
#endif