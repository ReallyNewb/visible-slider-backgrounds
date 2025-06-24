#include <Geode/Geode.hpp>
#include <Geode/modify/Slider.hpp>

using namespace geode::prelude;

class $modify(NewSlider, Slider) {
public:
	bool init(CCNode* p0, SEL_MenuHandler p1, char const* p2, char const* p3, char const* p4, char const* p5, float p6) {
		if (!Slider::init(p0, p1, p2, p3, p4, p5, p6)) return false;

		this->scheduleOnce(schedule_selector(NewSlider::onSlider), 0.f);
		return true;
	}

	void onSlider(float) {
		auto main = this->getChildByType<CCSprite>(0);
		if (!main) return;

		auto bg = main->getChildByType<CCSprite>(0);
		if (!bg) return;

		bg->setVisible(true);
	}
};