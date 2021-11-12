from __future__ import annotations
from abc import ABC, abstractmethod
from random import randint, uniform
from typing import List

"""
This is an example of using the template for observer pattern with weather data. 
Suppose we have barometer, temperature, and humidity sensors.
"""


class Subject(ABC):
    """
    The Subject interface declares a set of methods for managing subscribers.
    """

    @abstractmethod
    def attach(self, observer: Observer) -> None:
        """
        Attach an observer to the subject.
        """
        pass

    @abstractmethod
    def detach(self, observer: Observer) -> None:
        """
        Detach an observer from the subject.
        """
        pass

    @abstractmethod
    def notify(self) -> None:
        """
        Notify all observers about an event.
        """
        pass

class weather_data(Subject):
    """
    The Subject owns some important state and notifies observers when the state
    changes.
    """
    _state: dict = {}
    """
    For the sake of simplicity, the Subject's state, essential to all
    subscribers, is stored in this variable.
    """

    _observers: List[Observer] = []
    """
    List of subscribers. In real life, the list of subscribers can be stored
    more comprehensively (categorized by event type, etc.).
    """

    def attach(self, observer: Observer) -> None:
        """
        Register an observer to the subject.
        """
        print("Subject: Attached an observer")
        self._observers.append(observer)

    def detach(self, observer: Observer) -> None:
        """
        Remove a registered observer from the subject.
        """
        print("Subject: Detached an observer")
        self._observers.remove(observer)

    def notify(self) -> None:
        """
        Trigger an update in each subscriber.
        """
        print("Subject: Notifying observers...")
        for observer in self._observers:
            observer.update(self)

    def read_sensors(self, pressure: float, temp: float, humidity: int) -> None:
        """
        The Subject in real life usually maintains some list of subscribers.
        """
        # update pressure, temp, and humidity for the state
        self._state["pressure"] = pressure
        self._state["temp"] = temp
        self._state["humidity"] = humidity
        print(f"Subject: My state has just changed to: {self._state}")
        self.notify()

class Observer(ABC):
    """
    The Observer interface declares the update method, used by subjects.
    """

    @abstractmethod
    def update(self, subject: Subject) -> None:
        """
        Receive update from subject.
        """
        pass

"""
Concrete Observers react to the updates issued by the Subject they had been
attached to.
"""

class weather_conditions(Observer):
    temp: float
    pressure: float
    humidity: int
    def __init__(self):
        self.temp = 0.0
        self.pressure = 0.0
        self.humidity = 0

    def update(self, subject: Subject) -> None:
        self.temp = subject._state["temp"]
        self.pressure = subject._state["pressure"]
        self.humidity = subject._state["humidity"]
        self.display()

    def display(self) -> None:
        print(f"temp/pressure/humidity current: {self.temp}, {self.pressure}, {self.humidity}")

class weather_statistics(Observer):
    maxTemp: float
    minTemp: float
    tempSum: float
    numReadings: int
    def __init__(self):
        self.maxTemp = 0.0
        self.minTemp = 200.0
        self.tempSum = 0.0
        self.numReadings = 0
    def update(self, subject: Subject) -> None:
        self.tempSum += subject._state["temp"]
        self.numReadings += 1
        self.maxTemp = max(self.maxTemp, subject._state["temp"])
        self.minTemp = min(self.minTemp, subject._state["temp"])
        self.display()

    def display(self) -> None:
        print(f"Avg/Max/Min temperature = {self.tempSum/self.numReadings}, {self.maxTemp}, {self.minTemp}")

if __name__ == "__main__":
    # The client code.

    subject = weather_data()

    observer_conditions = weather_conditions()
    subject.attach(observer_conditions)

    observer_statistics = weather_statistics()
    subject.attach(observer_statistics)

    subject.read_sensors(uniform(900,1100),uniform(-20,200),randint(0,100))
    subject.read_sensors(uniform(900,1100),uniform(-20,200),randint(0,100))
    subject.read_sensors(uniform(900,1100),uniform(-20,200),randint(0,100))
    subject.read_sensors(uniform(900,1100),uniform(-20,200),randint(0,100))

    subject.detach(observer_statistics)

    subject.read_sensors(uniform(900,1100),uniform(-20,200),randint(0,100))