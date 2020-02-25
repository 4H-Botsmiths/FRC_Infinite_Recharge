/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include <frc/smartdashboard/SmartDashboard.h>
#include <cameraserver/CameraServer.h>

#include "Robot.h"

void Robot::RobotInit() {
    frc::CameraServer::GetInstance()->StartAutomaticCapture(0);
    frc::CameraServer::GetInstance()->StartAutomaticCapture(1);

    motorNW.RestoreFactoryDefaults();
    motorNE.RestoreFactoryDefaults();
    motorSE.RestoreFactoryDefaults();
    motorSW.RestoreFactoryDefaults();

    driveRocker.ClearAllPCMStickyFaults();
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

    if (auxController.GetTriggerRightDeadzone() > 0) {
        intakeArm.Extend();

        Timer tmp { 0.1 };
        tmp.Start();

        ballIntake.Set(BALL_INTAKE_SPEED);
    }
    else {
        intakeArm.Retract();
        ballIntake.Set(0);
    }

    shooter.Set(
        auxController.GetAButton() ? SHOOTER_SPEED : 0
    );

    if (auxController.GetLeftBumper()) {
        ballBelt.Set(-BALL_BELT_SPEED);
    }
    else if (auxController.GetRightBumper()) {
        ballBelt.Set(BALL_BELT_SPEED);
    }
    else {
        ballBelt.Set(0);
    }

    if (driveController.GetTriggerRightDeadzone() > 0) drivetrain.useNormal();
    else drivetrain.useMecanum();

    if ((driveController.GetTriggerLeftDeadzone() > 0)) {
        limelight.turnLightsOn();

        if (limelight.getTV()) {
            const double targetX=limelight.getTX();
            const double range=2;
            const double turnMultiplier=0.01;

            if (!(-range < targetX && targetX < range)) {
                if (targetX < 0) {
                    drivetrain.drive(
                        0,
                        -TURN_THRESHOLD - ( -targetX * turnMultiplier )
                    );
                }
                else {
                    drivetrain.drive(
                        0,
                        TURN_THRESHOLD + ( targetX * turnMultiplier )
                    );
                }
            }
        }
    }
    else {
        limelight.turnLightsOff();

        driveAUX.drive(&driveController);
    }
}

void Robot::TestPeriodic() {
    starDustRobot.TestPeriodic();
}

void Robot::DisabledInit() {}

#ifndef RUNNING_FRC_TESTS
int main() { return frc::StartRobot<Robot>(); }
#endif