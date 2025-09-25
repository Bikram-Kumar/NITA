#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include <signal.h>

namespace p1 {

    void* thread_func(void* arg) {
        printf("Thread running\n");
        pthread_exit(NULL);
    }

    int main() {
        pthread_t tid;
        pthread_create(&tid, NULL, thread_func, NULL);
        pthread_join(tid, NULL); // Wait for thread to finish
        printf("Thread terminated\n");
        return 0;
    }

}


namespace p2 {
    void* thread_func(void* arg) {
        printf("TID: %lu, PID: %d\n", pthread_self(), getpid());
        pthread_exit(NULL);
    }
    int main() {
        pthread_t tid;
        pthread_create(&tid, NULL, thread_func, NULL);
        pthread_join(tid, NULL);
        return 0;
    }

}


namespace p3 {
    void* print_message(void* msg) {
        printf("%s\n", (char*)msg);
        pthread_exit(NULL);
    }
    int main() {
        pthread_t tid;
        char* message = "Hello from thread!";
        pthread_create(&tid, NULL, print_message, (void*)message);
        pthread_join(tid, NULL);
        return 0;
    }
}


namespace p4 {
    void* compute_sum(void* arg) {
        int* nums = (int*)arg;
        int sum = nums[0] + nums[1];
        printf("Sum: %d\n", sum);
        pthread_exit(NULL);
    }
    int main() {
        pthread_t tid;
        int nums[2] = {5,7};
        pthread_create(&tid, NULL, compute_sum, (void*)nums);
        pthread_join(tid, NULL);
        return 0;
    }
}


namespace p5 {
    void handle_sigint(int sig) {
        printf("Caught SIGINT (Ctrl+C)\n");
    }
    int main() {
        signal(SIGINT, handle_sigint); // Register handler
        printf("Press Ctrl+C to test\n");
        pause();
        signal(SIGINT, SIG_DFL); // Unregister handler
        return 0;
    }
}



namespace p6 {

    void handler(int sig) {
        if (sig == SIGUSR1) {
            printf("Custom signal (SIGUSR1) received\n");
        }
    }
    
    int main() {
        signal(SIGUSR1, handler); // Custom signal
        printf("PID: %d\n", getpid());
        printf("Send SIGUSR1 via: kill -SIGUSR1 %d\n", getpid());
        pause(); // Wait for signal
        return 0;
    }
    
}



int main() {
    p1::main();
    p2::main();
    p3::main();
    p4::main();
    p5::main();
    p6::main();
    return 0;
}