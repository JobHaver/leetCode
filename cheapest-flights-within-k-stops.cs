public class Solution {
    public int FindCheapestPrice(int n, int[][] flights, int src, int dst, int k) {
        //absolutley insane way to innit a list of lists
        List<List<(int, int)>> dest = Enumerable.Range(0, n).Select(i => new List<(int, int)>()).ToList();
        int[] visited = Enumerable.Repeat<int>(Int32.MaxValue, n).ToArray();

        visited[src] = 0;
        foreach(int[] v in flights)
            dest[v[0]].Add((v[1], v[2]));

        Queue<(int, int)> curr = new Queue<(int, int)>();
        curr.Enqueue((src, 0));
        for(int i = -1; i < k; i++){
            for(int j = curr.Count(); j-- != 0; curr.Dequeue()){
                foreach((int, int) p in dest[curr.Peek().Item1]){
                    if(visited[p.Item1] > curr.Peek().Item2 + p.Item2){
                        visited[p.Item1] = curr.Peek().Item2 + p.Item2;
                        curr.Enqueue((p.Item1, visited[p.Item1]));
                    }
                }
            }
        }

        return visited[dst] == Int32.MaxValue ? -1 : visited[dst];
    }
}