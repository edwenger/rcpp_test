library(shiny)
library(here)
library(Rcpp)


sourceCpp(here("src", "Cohort.cpp"))


p_slider = sliderInput(inputId = "p",
                       label = "Daily death probability:",
                       min = 0,
                       max = 1,
                       value = 0.1)

n_slider = sliderInput(inputId = "n",
                       label = "Number of mosquitos:",
                       min = 0,
                       max = 1000,
                       value = 100)


ui = fluidPage(
  
  titlePanel("Binomial Random Draws"),
  
  sidebarLayout(
    sidebarPanel(p_slider, n_slider), 
    mainPanel(plotOutput(outputId = "distPlot"))
  )
)


server = function(input, output) {
  
  output$distPlot = renderPlot({
    
    c1 = new(Cohort, input$n)
    
    x = c()
    for (i in 1:input$n)
    {
      x[i] = c1$drawFraction(input$p)
    }
    
    bins = seq(min(x), max(x))
    
    hist(x, breaks = bins, col = "#75AADB", border = "white",
         xlab = "# in cohort that die",
         main = "Histogram of binomial death draws")
    
  })
  
}


shinyApp(ui, server)