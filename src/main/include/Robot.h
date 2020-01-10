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

class Robot : public frc::TimedRobot {
public:
	void RobotInit() override;
	void RobotPeriodic() override;
	void AutonomousInit() override;
	void AutonomousPeriodic() override;
	void TeleopInit() override;
	void TeleopPeriodic() override;
	void TestPeriodic() override;

private:
	//frc::Talon motor_0 { 0 };
	BetterMotor motor_0 { false, 0 };
	BetterMotor motor_1 { true, 0 };

	StarDustRobot starDustRobot {{
		&motor_0,
		&motor_1
	}};

	//frc::SendableChooser<std::string> m_chooser;
	//const std::string kAutoNameDefault = "Default";
	//const std::string kAutoNameCustom = "My Auto";
	//std::string m_autoSelected;
};
