#ifndef T1_DECODING_LIB_H
#define T1_DECODING_LIB_H

/*
 * ������ ������� ������ � �������� ������
 */
void decodeStep1(char **&content);

/*
 * ������ ������� ������ � �������� �������
 */
void decodeStep2(char **&content);

/*
 * �������� ������ 3�� ������ � ������ ������ �� ������ 7�� � �����
 */
void decodeStep3(char **&content);

/*
 * �������� ������ 2�� ������ � ������ ������� �� ������ 11�� � �����
 */
void decodeStep4(char **&content);

/*
 * ������������� ������ �����(������ ������ � ������� �������)
 */
void decodeStep5(char **&content);

/*
 * ����������� ������� �������� � ������ �������
 */
void decodeStep6(char **&content);

/*
 * ����������� ������� �������� �������� ��������
 */
void decodeStep7(char **&content);

/*
 * ������� ������� ������� �� ������ (i+j) ������ �� 13 �������� � ������� ASCII
 */
void decodeStep8(char **&content);

/*
 * ������� ������� ������� �� �������� (i+j) ����� �� 5 �������� � ������� ASCII
 */
void decodeStep9(char **&content);

#endif //T1_DECODING_LIB_H
