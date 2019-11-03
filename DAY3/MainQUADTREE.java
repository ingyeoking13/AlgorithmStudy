import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;

public class MainQUADTREE {

//	�뷮�� ��ǥ �����͸� �޸� �ȿ� ������ �����ϱ� ���� ����ϴ� ���� ��� �� ���� Ʈ��(quad tree)�� ���� �ֽ��ϴ�. 
//	�־��� ������ �׻� 4���� ������ ��������� ǥ���ϱ� ������ ���� Ʈ����� �̸��� �پ��µ�, 
//	���� ������ ���ó �� �ϳ��� ���� ���� �� ���ۿ� ���� ��� �׸��� ������ ǥ���ϴ� ���Դϴ�. 
//	���� Ʈ���� 2N �� 2N ũ���� ��� �׸��� ������ ���� ������ ���� ���ڿ��� �����մϴ�.

//	�� �׸��� ��� �ȼ��� ���� ���� ��� �� �׸��� ���� Ʈ�� ���� ����� �׸��� ũ�⿡ ������� b�� �˴ϴ�.
//	�� �׸��� ��� �ȼ��� �� ���� ��� �� �׸��� ���� Ʈ�� ���� ����� �׸��� ũ�⿡ ������� w�� �˴ϴ�.
//	��� �ȼ��� ���� ���� �ƴ϶��, ���� Ʈ���� �� �׸��� ���� ���η� ���� 2����� 4���� �������� �ɰ� �� ������ ���� Ʈ�� �����մϴ�. 
//	�̶� ��ü �׸��� ���� ����� x(���� �� �κ��� ���� ���)(������ �� �κ��� ���� ���)(���� �Ʒ� �κ��� ���� ���)(������ �Ʒ� �κ��� ���� ���)�� �˴ϴ�. ���� ��� �׸� (a)�� ���� �� 4�и��� xwwwb�� ����˴ϴ�.
//	�׸� (a)�� �׸� (b)�� 16��16 ũ���� ���� �׸��� ���� Ʈ���� ��� ������ �����ϴ����� �����ݴϴ�. 
//	�̶� ��ü �׸��� ���� ����� xxwwwb xw xwbbb ww xxxwwbbbwwwwbb�� �˴ϴ�.

//	���� ���ڽ��ϴ�.
//	wwwwwwwwwwwwwwbb
//	wwwwwwwwwwwwwwbb
//	wwwwwwwwwwwwbbbb
//	wwwwwwwwwwwwbbbb
//	wwwwbbbbwwwwwwww
//	wwwwbbbbwwwwwwww
//	wwwwbbbbwwwwwwww
//	wwwwbbbbwwwwwwww
//	wwbbwwwwbbbbbbbb
//	bbbbwwwwbbbbbbbb
//	wwwwwwwwbbbbbbbb
//	wwwwwwwwbbbbbbbb
//	wwwwbbbbbbbbbbbb
//	wwwwbbbbbbbbbbbb
//	wwwwbbbbbbbbbbbb
//	wwwwbbbbbbbbbbbb
	
//	���� Ʈ���� ����� ��� �׸��� �־����� ��, �� �׸��� ���Ϸ� ������ �׸� �� ���� Ʈ�� �����ؼ� ����ϴ� ���α׷��� �ۼ��ϼ���.

//	�Է�
//	ù �ٿ� �׽�Ʈ ���̽��� ���� C (C��50)�� �־����ϴ�. 
//	�� �� C�ٿ� �ϳ��� ���� Ʈ���� ������ �׸��� �־����ϴ�. ��� ���ڿ��� ���̴� 1,000 �����̸�, ���� �׸��� ũ��� 220 �� 220 �� ���� �ʽ��ϴ�.

//	���
//	�� �׽�Ʈ ���̽��� �� �ٿ� �־��� �׸��� ���Ϸ� ������ ����� ���� Ʈ�� �����ؼ� ����մϴ�.
	
	static int C;
	static int index;
	
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

		C = Integer.parseInt(br.readLine());

		for (int i = 0; i < C; i++) {
			String line = br.readLine();
			index = 0;
			String answer = reverse(line);

			bw.write(answer + "\n");
		}

		bw.flush();
		bw.close();
		br.close();
	}

	private static String reverse(String line) {
		char head = line.charAt(index);
		index++;
		if (head == 'b' || head == 'w') {
			return head + "";
		}

		String upperLeft = reverse(line);
		String upperRight = reverse(line);
		String lowerLeft = reverse(line);
		String lowerRight = reverse(line);

		return "x" + lowerLeft + lowerRight + upperLeft + upperRight;
	}

}
