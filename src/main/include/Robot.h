/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <string>

#include <frc/TimedRobot.h>
#include <frc/Talon.h>
#include <frc/smartdashboard/SendableChooser.h>

#include "StarDust/motor/BetterMotor.hpp"
#include "StarDust/core/StarDustRobot.hpp"
#include "StarDust/drive/DriveSpider.hpp"
#include "StarDust/sensor/motion/BetterGyro.hpp"
#include "StarDust/pneumatics/BetterDoubleSolenoid.hpp"
#include "StarDust/control/BetterController.hpp"
#include "StarDust/drive/DriveAUX.hpp"

class Robot : public frc::TimedRobot {
public:
	void RobotInit() override;
	void RobotPeriodic() override;
	void AutonomousInit() override;
	void AutonomousPeriodic() override;
	void TeleopInit() override;
	void TeleopPeriodic() override;
	void TestPeriodic() override;
	void DisabledInit() override;

private:
	BetterGyro gyro;

	BetterMotor driveMotor0 { 0 };
	BetterMotor driveMotor1 { 1 };
	BetterMotor driveMotor2 { 2 };
	BetterMotor driveMotor3 { 3 };
	BetterDoubleSolenoid driveRocker { 0, 1 };

	DriveSpider drivetrain {
		&driveMotor0,
		&driveMotor1,
		&driveMotor2,
		&driveMotor3,
		&driveRocker
	};

	DriveAUX driveAUX {
		&drivetrain,
		&gyro,
		0
	};

	BetterController xboxController { 0, 0.15, 0.15, {
		{BetterController::on::RightBumperPressed, [=]{
			drivetrain.useNormal();
		}},
		{BetterController::on::RightBumperReleased, [=]{
			drivetrain.useMecanum();
		}}
	}};

	StarDustRobot starDustRobot{{
		&gyro,
		&driveMotor0,
		&driveMotor1,
		&driveMotor2,
		&driveMotor3,
		&driveRocker,
		&drivetrain,
		&driveAUX,
		&xboxController
	}};
};
