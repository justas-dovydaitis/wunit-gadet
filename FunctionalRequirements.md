Čia pildome visus funkcinius reikalavimus, kurie atsiras ataskaitoje. Pradžioje išskaidau šį sąrašą į kuriamos sistemos dalis. Sąrašą galima pildyti ir redaguoti. 
## Aparatinės įrangos (hardware) funkciniai reikalavimai
- WindUnit'o Įvestys (inputs) turi būti konfigūruojami. (Reikia išplėsti, išvardinant visus galimas įvestis ir pan.).
## Mobiliosios aplikacijos (app'so) funkciniai reikalavimai
- Mobilioji aplikacija (App'sas) turi veikti background'e.
- Bendrauja su WindUnit per Bluetooth ryšį.
- Vartotojų registracijai, prisijungimui, duomenų talpinimui ir t.t. https://firebase.google.com/products/auth
## Backend'o funkciniai reikalavimai
- Naudojamas Firebase'o išvestiniai produktai
  - Vartotojų registracijai, prisijungimui, duomenų talpinimui ir t.t. https://firebase.google.com/products/auth
  - Statinių duomenų talpinimui Firestore https://firebase.google.com/products/firestore
  - Dinaminių (dažnai kintamų) duomenų talpinimui (jeigu atsiras poreikis) https://firebase.google.com/products/realtime-database
- NodeJS kaip serveris, kuriame bus apdorojami duomenys iš WindUnit, App, Website.
## Website'o funkciniai reikalavimai
- Turi būti galimybė matyti savo transpoto priemonę žemėlapyje pagal GPS duomenis.