-- Keep a log of any SQL queries you execute as you solve the mystery.
SELECT * FROM crime_scene_reports WHERE description LIKE '%duck%';

SELECT transcript FROM interviews WHERE transcript LIKE '%bakery%';

SELECT name FROM people WHERE license_plate IN
    (SELECT license_plate FROM bakery_security_logs WHERE year = 2023 AND month = 7 AND day = 28) ORDER BY name;

SELECT id, account_number FROM atm_transactions WHERE year = 2023 AND month = 7 AND day = 28 AND atm_location = 'Leggett Street';

SELECT name FROM people WHERE id IN
    (SELECT person_id FROM bank_accounts WHERE account_number IN
        (SELECT account_number FROM atm_transactions WHERE year = 2023 AND month = 7 AND day = 28 AND atm_location = 'Leggett Street'));

SELECT name FROM people WHERE phone_number IN
    (SELECT caller FROM phone_calls WHERE
        year = 2023 AND month = 7 AND day = 28
        AND duration < 60);

SELECT * FROM people WHERE name = 'Bruce';
SELECT * FROM people WHERE name = 'Diana';
SELECT * FROM people WHERE name = 'Taylor';

SELECT name FROM people WHERE phone_number IN
    (SELECT receiver FROM phone_calls
        WHERE year = 2023 AND month = 7 AND day = 28 AND duration < 60
        AND caller = '(367) 555-5533');
# Robin

SELECT * FROM people WHERE name = 'Robin';

SELECT id FROM airports WHERE city = 'Fiftyville';
# 8

SELECT id, hour FROM flights WHERE origin_airport_id = 8 AND year = 2023 AND month = 7 AND day = 29 ORDER BY hour;
# 36

SELECT passport_number FROM passengers WHERE flight_id = 36;

SELECT name FROM people WHERE phone_number IN
    (SELECT receiver FROM phone_calls
        WHERE year = 2023 AND month = 7 AND day = 28 AND duration < 60
        AND caller = '(770) 555-1861');
# Philip

SELECT * FROM people WHERE name = 'Philip';

SELECT name FROM people WHERE phone_number IN
    (SELECT receiver FROM phone_calls
        WHERE year = 2023 AND month = 7 AND day = 28 AND duration < 60
        AND caller = '(286) 555-6063');
# James

SELECT * FROM people WHERE name = 'James';

SELECT passport_number FROM passengers WHERE flight_id = 36 AND passport_number = 2438825627;

SELECT city FROM airports WHERE id = (SELECT destination_airport_id FROM flights WHERE id = 36);
