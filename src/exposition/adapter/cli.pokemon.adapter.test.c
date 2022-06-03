#include "cli.pokemon.adapter.h"
#include <assert.h>
#include <printf.h>
#include "../../kernel/string/string.utils.h"
#include "../../../test/test.h"
#include "../../kernel/date/date.h"

void itShouldAdaptPikachu();
void itShouldAdaptThreePikachu();
void itShouldAdaptElectricPikachu();
void itShouldAdaptSeenPikachu();
void itShouldAdaptCapturedPikachu();

int main() {

    itShouldAdaptPikachu();
    itShouldAdaptThreePikachu();
    itShouldAdaptElectricPikachu();
    itShouldAdaptSeenPikachu();
    itShouldAdaptCapturedPikachu();

    return 0;
}

void itShouldAdaptPikachu() {
    Pokemon pikachu = newPokemon(
            newString("Pikachu"),
            0,
            None,
            NULL,
            NULL);
    String response = adaptToCliPokemonResponse(pikachu);
    assert(
            assertExpectedStringEqualsActual(
                    "Pikachu x0\n"
                    "    Type Inconnu\n"
                    "    Jamais découvert\n"
                    "    Jamais capturé\n",
                    stringValue(response)
            )
            );
    freePokemon(pikachu);
    freeString(response);
}

void itShouldAdaptThreePikachu() {
    Pokemon pikachu = newPokemon(
            newString("Pikachu"),
            3,
            None,
            NULL,
            NULL
    );
    String response = adaptToCliPokemonResponse(pikachu);
    assert(
            assertExpectedStringEqualsActual(
                    "Pikachu x3\n"
                    "    Type Inconnu\n"
                    "    Jamais découvert\n"
                    "    Jamais capturé\n",
                    stringValue(response)
            )
    );
    freePokemon(pikachu);
    freeString(response);
}

void itShouldAdaptElectricPikachu() {
    Pokemon pikachu = newPokemon(
            newString("Pikachu"),
            3,
            Electric,
            NULL,
            NULL
    );
    String response = adaptToCliPokemonResponse(pikachu);
    assert(
            assertExpectedStringEqualsActual(
                    "Pikachu x3\n"
                    "    Type Electrique\n"
                    "    Jamais découvert\n"
                    "    Jamais capturé\n",
                    stringValue(response)
            )
    );
    freePokemon(pikachu);
    freeString(response);
}

void itShouldAdaptSeenPikachu() {
    Pokemon pikachu = newPokemon(
            newString("Pikachu"),
            3,
            None,
            newDate(2022, MAY, 27),
            NULL
    );
    String response = adaptToCliPokemonResponse(pikachu);
    assert(
            assertExpectedStringEqualsActual(
                    "Pikachu x3\n"
                    "    Type Inconnu\n"
                    "    Découvert la première fois le 27 mai 2022\n"
                    "    Jamais capturé\n",
                    stringValue(response)
            )
    );
    freePokemon(pikachu);
    freeString(response);
}

void itShouldAdaptCapturedPikachu() {
    Pokemon pikachu = newPokemon(
            newString("Pikachu"),
            3,
            None,
            NULL,
            newDate(2022, MAY, 27)
    );
    String response = adaptToCliPokemonResponse(pikachu);
    assert(
            assertExpectedStringEqualsActual(
                    "Pikachu x3\n"
                    "    Type Inconnu\n"
                    "    Jamais découvert\n"
                    "    Capturé la première fois le 27 mai 2022\n",
                    stringValue(response)
            )
    );
    freePokemon(pikachu);
    freeString(response);
}
