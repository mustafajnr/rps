#include <memory>
#include <vector>

namespace rps {

    class Observer;
    using ObserverPtr = std::shared_ptr<Observer>;

    class Event;
    using EventPtr = std::shared_ptr<Event>;

    class Observable
    {
    public:
        void notifyAll(EventPtr& event)
        {
            for (auto observer : observers_)
            {
                observer.notify(event);
            }
        }
        void addObserver(ObserverPtr& observer)
        {
            observers_.push_back(observer);
        }
    private:
        std::vector<ObserverPtr> observers_;
    };
}