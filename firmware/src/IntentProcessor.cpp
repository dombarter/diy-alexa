#include <Arduino.h>
#include "IntentProcessor.h"
#include "Speaker.h"

IntentProcessor::IntentProcessor(Speaker *speaker)
{
    m_speaker = speaker;
    pinMode(GPIO_NUM_13, OUTPUT);
}

IntentResult IntentProcessor::toggleLights(const Intent &intent) {

    if (intent.intent_confidence < 0.8)
    {
        Serial.printf("Only %.f%% certain on intent\n", 100 * intent.intent_confidence);
        return FAILED;
    }
    if (intent.trait_value.empty())
    {
        Serial.println("Can't work out the intent action");
        return FAILED;
    }
    if (intent.trait_confidence < 0.8)
    {
        Serial.printf("Only %.f%% certain on trait\n", 100 * intent.trait_confidence);
        return FAILED;
    }
    bool is_turn_on = intent.trait_value == "on";

    // TODO Swap this to the 433MHz transmitter
    digitalWrite(GPIO_NUM_13, is_turn_on);

    return SUCCESS;
}

IntentResult IntentProcessor::processIntent(const Intent &intent)
{
    if (intent.text.empty())
    {
        Serial.println("No text recognised");
        return FAILED;
    }
    Serial.printf("I heard \"%s\"\n", intent.text.c_str());
    if (intent.intent_name.empty())
    {
        Serial.println("Can't work out what you want to do with the device...");
        return FAILED;
    }
    Serial.printf("Intent is %s\n", intent.intent_name.c_str());
    if (intent.intent_name == "toggle_lights")
    {
        return toggleLights(intent);
    }

    return FAILED;
}
