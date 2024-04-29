#EML Scan

[TOCM]

#About

###Description

Project written in C that scans .eml file provided as an argument and is looking for pesel numbers (Polish ID numbers) inside. Program is compatible with Windows and Linux systems. **Attachments in .eml file have to be only .txt, because program can't read text content from docx, pdf, etc. formatted files.**

###Features

- Attachment extraction with base64 decoding
- Attachments are saved in a directory named **attachments(example.eml)**
- Pesel number validation
- Program takes .eml path as a parameter
- Provided path and .eml file validation
- In eml_examples directory I provided several .eml example files
- Every action is saved to log.txt file with current date

#Installation

1. Clone this repository:
   `$ git clone https://github.com/pZmudzki/scan_eml.git`

2. Open Clion and click "Open":
   ![step 2](https://github.com/pZmudzki/scan_eml/blob/media/images/step2.png?raw=true)

3. Select cloned project directory and click "OK":
   ![step 3](https://github.com/pZmudzki/scan_eml/blob/media/images/step3.png?raw=true)

4. Click "OK" in CMake Project Wizard:
   ![step 4](https://github.com/pZmudzki/scan_eml/blob/media/images/step4.png?raw=true)

5. Wait until the configuration is done (Clion should display something similar to marked space on an image below) and you'll be ready to go:
   ![step 5](https://github.com/pZmudzki/scan_eml/blob/media/images/step5.png?raw=true)

#Usage

1. In the right corner of CLion window click on 3 dots icon and then "Edit...":
   ![step 6](https://github.com/pZmudzki/scan_eml/blob/media/images/step6.png?raw=true)

2. Then type in .eml file path into "Program arguments" field, apply changes and click "OK":
   ![step 7](https://github.com/pZmudzki/scan_eml/blob/media/images/step7.png?raw=true)

3. Click the green arrow icon in the corner to start scanning:
   ![step 8](https://github.com/pZmudzki/scan_eml/blob/media/images/step8.png?raw=true)

4. On the bottom there will appear a console window with programs output.
   ![step 9](https://github.com/pZmudzki/scan_eml/blob/media/images/step9.png?raw=true)

5. In the cmake-build-debug folder (scan_eml executable directory) will appear log.txt containg programs actions and a folder with extracted and decoded attachments.
   ![step 10](https://github.com/pZmudzki/scan_eml/blob/media/images/step10.png?raw=true)
   ![step 11](https://github.com/pZmudzki/scan_eml/blob/media/images/step11.png?raw=true)
