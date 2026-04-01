// M5Lab1
// CSC 134 - M5LAB1 Choose Your Own Adventure
// Galactic Grab-N-Go: A Sci-Fi Convenience Store
// Jayla Harper
// 04/01/26

#ifndef ADVENTURE_H
#define ADVENTURE_H

// ── Main menu ──────────────────────────────────────────────
void main_menu();

// ── Level 1 choices ────────────────────────────────────────
void choice_browse();       // 1. Browse the shelves
void choice_clerk();        // 2. Talk to the alien clerk
void choice_leave();        // 3. Leave the store

// ── Level 2 – Browse path ──────────────────────────────────
void choice_snacks();       // 1a. Alien snacks aisle
void choice_gadgets();      // 1b. Gadget display case 

// ── Level 2 – Clerk path ───────────────────────────────────
void choice_job();          // 2a. Ask for a job
void choice_rumor();        // 2b. Ask about the back-room rumors

// ── Level 2 – Leave path ───────────────────────────────────
void choice_alley();        // 3a. Investigate the dark alley

// ── Endings ────────────────────────────────────────────────
void end_poisoned();
void end_snack_rich();
void end_hired();
void end_beatup();
void end_hero();
void end_steal();
void end_dont_steal();

#endif