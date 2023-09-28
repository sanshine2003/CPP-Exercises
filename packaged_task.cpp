#include <iostream>
#include <future>
#include <thread>
#include <mutex>
#include <condition_variable>

using namespace std;


struct ICallBack {
  virtual ~ICallBack() = default;
  
  virtual void CallMe() = 0;  
};

template<typename CALLBACK>
struct CallBack : public ICallBack {
    CallBack(CALLBACK c) : _c(std::move(c)) {}
    void CallMe() override { _c(); };
    std::function<CALLBACK> _c;
};

class TestCallback {
public:

template<typename CALLBACK>
void CallMeBack(CALLBACK c) const {
    c(_themagicnumberis);
};

template<typename CALLBACK>
void CallMeBack2(CALLBACK c) const {
    std::this_thread::sleep_for(std::chrono::milliseconds(2000));
    c();
};

void Register(ICallBack& c) {
    _callback = &c;
}
void Unregister(ICallBack& c) {
    if( _callback == &c) {
        _callback = nullptr;
    }
}

void CallMeBack3() const {
    if(_callback) {
        _callback->CallMe();
    }
}

private:
    const uint32_t _themagicnumberis = 42;
    ICallBack* _callback;
};

int main()
{
    
    TestCallback c;
    
{
    std::packaged_task<uint32_t(uint32_t)> task([](uint32_t value) -> uint32_t {return value;});
    std::future<uint32_t> result = task.get_future();
    c.CallMeBack(std::move(task));
    cout<<"and the value is: " << result.get() << endl;    
}
{
    std::packaged_task<void()> task([](){});
    std::future<void> result = task.get_future();
    cout << "waiting..." << endl;
    c.CallMeBack2(std::move(task));
    result.wait();
    cout << "done" << endl;
}

{
    std::mutex m;
    std::condition_variable cv;
    std::thread t1( [&c, &cv]{ c.CallMeBack2([&cv](){ cv.notify_all(); }); });
    cout << "waiting..." << endl;
    std::unique_lock<std::mutex> lk(m);
    cv.wait(lk);
    cout << "done" << endl;
    t1.join();    
}

{
    struct CallBack : public ICallBack {
        void CallMe() override { cout << "In CallMe" << endl; };
    };

    CallBack cc;
    c.Register(cc);
    c.CallMeBack3();
    c.Unregister(cc);
}
{
    CallBack<void()> cc([](){cout << "In CallMe" << endl;});
    c.Register(cc);
    c.CallMeBack3();
    c.Unregister(cc);
}


    return 0;
}
